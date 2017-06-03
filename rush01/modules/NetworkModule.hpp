#ifndef CPPBOOTCAMP_NETWORKMODULE_H
#define CPPBOOTCAMP_NETWORKMODULE_H

#include "../IMonitorModule.hpp"

namespace module
{
    class NetworkModule : public IMonitorModule
    {
    public:
        NetworkModule(std::string moduleName);
        ~NetworkModule();

        void        setModuleValue();
        std::string getModuleValue();

    private:
        NetworkModule();
        NetworkModule(NetworkModule const &copy);
        NetworkModule &operator=(NetworkModule const &copy);
    };
}

#endif
