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

int main(int argc, char **argv)
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

    if (argc > 1)
    {
        if(strncmp(argv[0], "test", 3)) {}
    }

    std::string pick = "";
    do {
        std::cout << "graphic interface or terminal?" << std::endl;
        std::cin >> pick;
    } while(strcmp(pick.c_str(), "graphic") != 0 && strcmp(pick.c_str(), "terminal") != 0);


    if (strcmp(pick.c_str(), "graphic") == 0)
    {
        std::vector<module::IMonitorModule*>::iterator it, end;
        display::graphics::Window *graph = new display::graphics::Window();
        graph->setModules(modules);
        al_start_timer(graph->timer);
        while(1)
        {
            al_wait_for_event(graph->event_queue, &graph->ev);
            if(graph->ev.type == ALLEGRO_EVENT_TIMER) {
                graph->_redraw = true;
            }
            if(graph->ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                break;
            }

            if(graph->_redraw && al_is_event_queue_empty(graph->event_queue)) {
                graph->_redraw = false;
                for(it = modules.begin(); it != modules.end(); it++)
                    (*it)->setModuleValue();
                graph->updateDisplay();
            }
        }
        delete graph;
    }
    else if (strcmp(pick.c_str(), "terminal") == 0)
    {
        display::text::Window *text = new display::text::Window();
        text->setModules(modules);

        std::vector<module::IMonitorModule*>::iterator it, end;

        int		key ;
        while (true)
        {
            nodelay(stdscr, true);
            key = getch();
            text->updateDisplay();
            sleep(1);
            if (key == 113 || key == 27)
                break;
            for(it = modules.begin(); it != modules.end(); it++)
                (*it)->setModuleValue();
        }

        delete text;
    }

    return 0;
}