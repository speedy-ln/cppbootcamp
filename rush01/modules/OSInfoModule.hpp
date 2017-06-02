#ifndef CPPBOOTCAMP_OSINFOMODULE_H
#define CPPBOOTCAMP_OSINFOMODULE_H

#include "../IMonitorModule.hpp"

namespace module
{
    class OSInfoModule : public IMonitorModule
    {
    public:
        OSInfoModule(std::string moduleName);
        ~OSInfoModule();

        void        setModuleValue();
        std::string getModuleValue();

    private:
        OSInfoModule();
        OSInfoModule(OSInfoModule const &copy);
        OSInfoModule &operator=(OSInfoModule const &copy);
    };
}

#endif
