#include "RAMModule.hpp"

namespace module
{
    RAMModule::RAMModule(std::string moduleName)
    {
        _moduleName = moduleName;
        setModuleValue();
    }

    RAMModule::~RAMModule() {}

    std::vector<std::string> RAMModule::memString()
    {
        int64_t total_mem;
        int64_t used_mem = 0;
        int64_t unused_mem;
        vm_size_t page_size;
        mach_port_t mach_port;
        mach_msg_type_number_t count;
        vm_statistics_data_t vm_stats;
        std::vector<std::string> str(2);

        int mib[2];
        mib[0] = CTL_HW;
        mib[1] = HW_MEMSIZE;
        size_t length = sizeof(int64_t);
        sysctl(mib, 2, &total_mem, &length, NULL, 0);

        mach_port = mach_host_self();
        count = sizeof(vm_stats) / sizeof(natural_t);
        if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
            KERN_SUCCESS == host_statistics(mach_port, HOST_VM_INFO, (host_info_t)&vm_stats, &count))
        {
            unused_mem = (int64_t)vm_stats.free_count * (int64_t)page_size;

            used_mem = ((int64_t)vm_stats.active_count +
                        (int64_t)vm_stats.inactive_count +
                        (int64_t)vm_stats.wire_count) *  (int64_t)page_size;
        }
        used_mem /= 1024;
        total_mem /= 1024;

        str[0] = "Used: " + templates::tostr((used_mem/1024)) + "MB";
        str[1] = "Total:  " + templates::tostr(total_mem/1024) + "MB";
        return str;
    }

    void RAMModule::setModuleValue()
    {
        this->_moduleValue.resize(2);
        this->_moduleValue = memString();
    }

    std::string RAMModule::getModuleValue()
    {
        return "Used: " + _moduleValue[0] + "Mb Total: " + _moduleValue[1] + "Mb";
    }
}