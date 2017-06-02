#ifndef IMONITOR_MODULE_HPP
#define IMONITOR_MODULE_HPP

#include "RushIncluces.hpp"

namespace module
{
    class IMonitorModule
    {
    public:
        IMonitorModule();
        virtual ~IMonitorModule();

        virtual void    setModuleValue() = 0;
        virtual std::string getModuleValue() = 0;
        std::string getModuleName() const;
        std::vector<std::string> getValues() const;

    protected:
        std::string                 _moduleName;
        std::vector<std::string>    _moduleValue;

    private:
        IMonitorModule(IMonitorModule const &copy);
        IMonitorModule &operator=(IMonitorModule const &copy);
    };
}

#endif