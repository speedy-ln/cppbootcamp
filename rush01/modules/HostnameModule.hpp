#ifndef CPPBOOTCAMP_HOSTNAMEMODULE_H
#define CPPBOOTCAMP_HOSTNAMEMODULE_H

#include "../IMonitorModule.hpp"

namespace module
{
    class HostnameModule : public IMonitorModule
    {
    public:
        HostnameModule(std::string moduleName);
        ~HostnameModule();

        void        setModuleValue();
        std::string getModuleValue();

    private:
        HostnameModule();
        HostnameModule(HostnameModule const &copy);
        HostnameModule &operator=(HostnameModule const &copy);
    };
}

#endif
