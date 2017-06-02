#include "TimeModule.hpp"

namespace module
{
    TimeModule::TimeModule(std::string moduleName)
    {
        _moduleValue.resize(2);
        _moduleName = moduleName;
        setModuleValue();
    }

    TimeModule::~TimeModule() {}

    void TimeModule::setModuleValue()
    {
        time_t		t;
        char		buffer[100];
        size_t		ret;

        time(&t);
        ret = std::strftime(buffer, sizeof(buffer) - 1, "%a %d %b %y", localtime(&t));
        this->_moduleValue[0].assign(buffer, ret);
        std::strftime(buffer, sizeof(buffer) - 1, "%r", localtime(&t));
        this->_moduleValue[1].assign(buffer, ret - 2);
    }

    std::string TimeModule::getModuleValue() { return (_moduleValue[0] + " " + _moduleValue[1]); }
}
