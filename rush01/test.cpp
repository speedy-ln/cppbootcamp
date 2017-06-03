#include "RushIncluces.hpp"
#include "modules/HostnameModule.hpp"
#include "modules/OSInfoModule.hpp"
#include "modules/TimeModule.hpp"
#include "modules/CPUModule.hpp"
#include <memory>

int main()
{
    module::HostnameModule *hostname = new module::HostnameModule("Hostname");
    std::cout << "module name: " << hostname->getModuleName() << std::endl;
    std::cout << "module value: " << hostname->getModuleValue() << std::endl;

    module::OSInfoModule *osinfo = new module::OSInfoModule("OS info");
    std::cout << "module name: " << osinfo->getModuleName() << std::endl;
    std::cout << "module value: " << osinfo->getModuleValue() << std::endl;

    module::TimeModule *timemodule = new module::TimeModule("Date Time");
    std::cout << "module name: " << timemodule->getModuleName() << std::endl;
    std::cout << "module value: " << timemodule->getModuleValue() << std::endl;

    module::CPUModule *cpumodule = new module::CPUModule("CPU");
    std::cout << "module name: " << cpumodule->getModuleName() << std::endl;
    std::cout << "module value: " << cpumodule->getModuleValue() << std::endl;


    return 0;
}