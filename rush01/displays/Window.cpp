#include "Window.hpp"
#include "Line.hpp"

namespace display
{
    namespace text
    {
        Window::Window()
        {
            _width = 30;
            initscr();                      // Start ncurses mode
            noecho();                       // Don't echo keystrokes
            cbreak();                       // Disable line buffering
            keypad(stdscr, true);
//            nodelay(stdscr, true);
            curs_set(0);
            updateDisplay();
        }

        Window::~Window()
        {
            clear();
            refresh();
            endwin(); //end ncurses mode
        }

        int Window::getWidth() { return _width; }

        std::vector<module::IMonitorModule *> Window::getModules() { return _modules; }
        void Window::setModules(std::vector < module::IMonitorModule * > mods)
        {
            _modules = mods;
        }

        int Window::updateDisplay()
        {
            Line line(getWidth());
            printw(line.top.c_str());
            printw(line.blank.c_str());
            printw(line.getCenteredText("ft_gkrellm").c_str());
            line.setCustom("System Monitor");
            printw(line.custom.c_str());
            printw(line.blank.c_str());
            printw(line.top.c_str());

            std::vector<module::IMonitorModule*>::iterator module, end;
            for(module = _modules.begin(), end = _modules.end(); module != end; module++)
            {
                std::vector<std::string>::iterator str;
                std::vector<std::string> vals = (*module)->getValues();
                printw(line.getCenteredText((*module)->getModuleName()).c_str());
                printw(line.filler.c_str());
                for (str = vals.begin(); str != vals.end(); str++)
                    printw(line.getCenteredText(*str).c_str());
                printw(line.top.c_str());
            }
            return (0);
        }
    }
}