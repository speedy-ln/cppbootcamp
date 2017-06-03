#ifndef CPPBOOTCAMP_WINDOW_H
#define CPPBOOTCAMP_WINDOW_H

#include "../IMonitorDisplay.hpp"
#include "../IMonitorModule.hpp"

namespace display
{
    namespace text
    {
        class Window : public IMonitorDisplay
        {
        public:
            Window();
            ~Window();

            int     updateDisplay();
            int     getWidth();
            void    setModules(std::vector<module::IMonitorModule*> mods);
            std::vector<module::IMonitorModule*>    getModules();

        private:
            Window(Window const &copy);
            Window &operator=(Window const &copy);

            int _width;
            std::vector<module::IMonitorModule*>    _modules;
//            std::vector<display::text::Line>        _lines;
        };
    }
}

#endif
