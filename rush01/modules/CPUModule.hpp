#ifndef CPPBOOTCAMP_CPUMODULE_H
#define CPPBOOTCAMP_CPUMODULE_H

#include "../IMonitorModule.hpp"

namespace module
{
    class CPUModule : public IMonitorModule
    {
    public:
        CPUModule(std::string moduleName);
        ~CPUModule();

        std::vector<float>          cpuPercentage();
        host_cpu_load_info_data_t   getCpuPercentages();

        void        setModuleValue();
        std::string getModuleValue();

    private:
        CPUModule();
        CPUModule(CPUModule const &copy);
        CPUModule &operator=(CPUModule const &copy);
    };
}

#endif
