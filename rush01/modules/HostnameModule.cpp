#include "HostnameModule.hpp"

namespace module
{
    HostnameModule::HostnameModule(std::string moduleName)
    {
        _moduleName = moduleName;
        char		buffer[100];

        buffer[0] = '\0';
        if (gethostname(buffer, sizeof(buffer) - 1) != 0)
            this->_moduleValue[0] = "unable to value";
        else
        {
            this->_moduleValue.resize(1);
            this->_moduleValue[0] = buffer;
        }
        setModuleValue();
    }
    HostnameModule::~HostnameModule() {}

    void HostnameModule::setModuleValue()
    {

    }

    std::string HostnameModule::getModuleValue()
    {
        return _moduleValue[0];
    }

}