#include "OSInfoModule.hpp"

namespace module
{
    OSInfoModule::OSInfoModule(std::string moduleName)
    {
        _moduleName = moduleName;
        setModuleValue();
    }
    OSInfoModule::~OSInfoModule() {}

    void OSInfoModule::setModuleValue()
    {
        char	kernostype[100];
        char	kernosrelease[100];
        size_t	size = 100;

        sysctlbyname("kern.ostype", &kernostype, &size, NULL, 0);
        sysctlbyname("kern.osrelease", &kernosrelease, &size, NULL, 0);
        this->_moduleValue.resize(2);
        this->_moduleValue[0] = "Type: ";
        this->_moduleValue[0] += kernostype;
        this->_moduleValue[1] = "Release: ";
        this->_moduleValue[1] += kernosrelease;
    }

    std::string OSInfoModule::getModuleValue()
    {
        return (_moduleValue[0] + " " + _moduleValue[1]);
    }
}