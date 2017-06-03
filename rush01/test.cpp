#include "RushIncluces.hpp"
#include "modules/HostnameModule.hpp"
#include "modules/OSInfoModule.hpp"
#include "modules/TimeModule.hpp"
#include "modules/CPUModule.hpp"
#include "modules/RAMModule.hpp"
#include "modules/NetworkModule.hpp"
#include "displays/Window.hpp"
#include "displays/Line.hpp"
#include <memory>

int main()
{

    std::vector<module::IMonitorModule*> modules;

    module::HostnameModule *hostname = new module::HostnameModule("Hostname");
    module::OSInfoModule *osinfo = new module::OSInfoModule("OSinfo");
    module::TimeModule *timemodule = new module::TimeModule("Date Time");
    module::CPUModule *cpumodule = new module::CPUModule("CPU");
    module::RAMModule *rammodule = new module::RAMModule("RAM");
    module::NetworkModule *networkmodule = new module::NetworkModule("Network");
    modules.push_back(hostname);
    modules.push_back(osinfo);
    modules.push_back(timemodule);
    modules.push_back(cpumodule);
    modules.push_back(rammodule);
    modules.push_back(networkmodule);

    display::text::Window *text = new display::text::Window();
    text->setModules(modules);
//    display::text::Line line(text->getWidth());

//    line.setCustom("System Monitor");
    int		key;
    while (true)
    {
        key = getch();
        clear();
        refresh();

        text->updateDisplay();
//        printw(line.top.c_str());
//        printw(line.custom.c_str());
//        printw(line.blank.c_str());
//        printw(line.filler.c_str());
//        printw(line.filler.c_str());
//        printw(line.filler.c_str());
//        printw(line.top.c_str());
        if (key == 113 || key == 27)
            break;
//        usleep(1000000/3);
    }

    delete text;

//    std::cout << "module name: " << hostname->getModuleName() << std::endl;
//    std::cout << "module value: " << hostname->getModuleValue() << std::endl;
//
//
//    std::cout << "module name: " << osinfo->getModuleName() << std::endl;
//    std::cout << "module value: " << osinfo->getModuleValue() << std::endl;
//
//    std::cout << "module name: " << timemodule->getModuleName() << std::endl;
//    std::cout << "module value: " << timemodule->getModuleValue() << std::endl;
//
//    std::cout << "module name: " << cpumodule->getModuleName() << std::endl;
//    std::cout << "module value: " << cpumodule->getModuleValue() << std::endl;
//
//    std::cout << "module name: " << rammodule->getModuleName() << std::endl;
//    std::cout << "module value: " << rammodule->getModuleValue() << std::endl;
//
//    std::cout << "module name: " << networkmodule->getModuleName() << std::endl;
//    std::cout << "module value: " << networkmodule->getModuleValue() << std::endl;

    return 0;
}