#ifndef CPPBOOTCAMP_TIMEMODULE_H
#define CPPBOOTCAMP_TIMEMODULE_H

#include "../IMonitorModule.hpp"

namespace module
{
    class TimeModule : public IMonitorModule
    {
    public:
        TimeModule(std::string moduleName);
        ~TimeModule();

        void        setModuleValue();
        std::string getModuleValue();

    private:
        TimeModule();
        TimeModule(TimeModule const &copy);
        TimeModule &operator=(TimeModule const &copy);
    };
}

#endif
