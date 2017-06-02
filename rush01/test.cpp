#include "RushIncluces.hpp"
#include "modules/HostnameModule.hpp"
#include "modules/OSInfoModule.hpp"
#include <memory>

int main()
{
    module::HostnameModule *hostname = new module::HostnameModule("Hostname");
    std::cout << "module name: " << hostname->getModuleName() << std::endl;
    std::cout << "module value: " << hostname->getModuleValue() << std::endl;

    module::OSInfoModule *osinfo = new module::OSInfoModule("OSinfo");
    std::cout << "module name: " << osinfo->getModuleName() << std::endl;
    std::cout << "module value: " << osinfo->getModuleValue() << std::endl;
    return 0;
}