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
        };
    }

    namespace graphics
    {
        class Window : public IMonitorDisplay
        {
        public:
            Window();
            ~Window();

            int     updateDisplay();
            void    setModules(std::vector<module::IMonitorModule*> mods);
            std::vector<module::IMonitorModule*>    getModules();

            ALLEGRO_EVENT       ev;
            ALLEGRO_TIMEOUT     timeout;
            ALLEGRO_EVENT_QUEUE *event_queue;
            ALLEGRO_TIMER       *timer;
            float         FPS;
            bool                _redraw;

        private:
            Window(Window const &copy);
            Window &operator=(Window const &copy);

            ALLEGRO_DISPLAY     *display;
            ALLEGRO_FONT        *font;
            std::vector<module::IMonitorModule*>    _modules;
        };
    }
}

#endif
