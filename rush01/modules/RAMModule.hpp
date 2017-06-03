#ifndef CPPBOOTCAMP_RAMMODULE_H
#define CPPBOOTCAMP_RAMMODULE_H

#include "../IMonitorModule.hpp"

namespace module
{
    class RAMModule : public IMonitorModule
    {
    public:
        RAMModule(std::string moduleName);
        ~RAMModule();

        std::vector<std::string>    memString();

        void        setModuleValue();
        std::string getModuleValue();

    private:
        RAMModule();
        RAMModule(RAMModule const &copy);
        RAMModule &operator=(RAMModule const &copy);
    };
}

#endif
