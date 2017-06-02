#include "IMonitorModule.hpp"

namespace module
{
    IMonitorModule::IMonitorModule() {}
    IMonitorModule::~IMonitorModule() {}
    std::string IMonitorModule::getModuleName() const { return _moduleName; }
    std::vector<std::string> IMonitorModule::getValues() const { return _moduleValue; }

}