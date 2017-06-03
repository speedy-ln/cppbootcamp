#include "CPUModule.hpp"

namespace module
{
    CPUModule::CPUModule(std::string moduleName)
    {
        _moduleName = moduleName;
        char			buf[100];
        size_t			buflen = 100;

        this->_moduleValue.resize(5);
        sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);
        this->_moduleValue[0].assign(buf, buflen);
        setModuleValue();
    }

    CPUModule::~CPUModule() {}


    host_cpu_load_info_data_t CPUModule::getCpuPercentages()
    {
        kern_return_t    error;
        mach_msg_type_number_t  count;
        host_cpu_load_info_data_t  cpuinfo;
        mach_port_t    mach_port;

        count = HOST_CPU_LOAD_INFO_COUNT;
        mach_port = mach_host_self();
        error = host_statistics(mach_port, HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count);
        if (error != KERN_SUCCESS)
        {
            return host_cpu_load_info_data_t();
        }

        return cpuinfo;
    }

    std::vector<float> CPUModule::cpuPercentage()
    {
        std::vector<float> cpu(5);
        host_cpu_load_info_data_t load1 = getCpuPercentages();
        usleep(100000);
        host_cpu_load_info_data_t load2 = getCpuPercentages();


        unsigned long long current_user    = load1.cpu_ticks[CPU_STATE_USER];
        unsigned long long current_system  = load1.cpu_ticks[CPU_STATE_SYSTEM];
        unsigned long long current_nice    = load1.cpu_ticks[CPU_STATE_NICE];
        unsigned long long current_idle    = load1.cpu_ticks[CPU_STATE_IDLE];

        unsigned long long next_user       = load2.cpu_ticks[CPU_STATE_USER];
        unsigned long long next_system     = load2.cpu_ticks[CPU_STATE_SYSTEM];
        unsigned long long next_nice       = load2.cpu_ticks[CPU_STATE_NICE];
        unsigned long long next_idle       = load2.cpu_ticks[CPU_STATE_IDLE];

        unsigned long long diff_user       = next_user - current_user;
        unsigned long long diff_system     = next_system - current_system;
        unsigned long long diff_nice       = next_nice - current_nice;
        unsigned long long diff_idle       = next_idle - current_idle;

        cpu[0] = static_cast<float>(diff_user)/static_cast<float>(diff_user + diff_system + diff_nice + diff_idle)*100.0;
        cpu[1] = static_cast<float>(diff_system)/static_cast<float>(diff_user + diff_system + diff_nice + diff_idle)*100.0;
        cpu[2] = static_cast<float>(diff_nice)/static_cast<float>(diff_user + diff_system + diff_nice + diff_idle)*100.0;
        cpu[3] = static_cast<float>(diff_idle)/static_cast<float>(diff_user + diff_system + diff_nice + diff_idle)*100.0;
        cpu[4] = static_cast<float>(diff_user + diff_system + diff_nice)/static_cast<float>(diff_user + diff_system + diff_nice + diff_idle)*100.0;

        return cpu;
    }



    void CPUModule::setModuleValue()
    {
        std::vector<float> cpu = cpuPercentage();
        this->_moduleValue[2] = "user: " + templates::tostr(roundf(cpu[0])) + "%";
        this->_moduleValue[3] = "system: " + templates::tostr(roundf(cpu[1])) + "%";
        this->_moduleValue[4] = "idle: " + templates::tostr(roundf(cpu[3])) + "%";
        this->_moduleValue[5] = "nice: " + templates::tostr(roundf(cpu[2])) + "%";
    }

    std::string CPUModule::getModuleValue()
    {
        return (
                _moduleValue[0] + " " + _moduleValue[1]
                + _moduleValue[2] + " " + _moduleValue[3]
                + _moduleValue[4] + " " + _moduleValue[5]
        );
    }
}