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
//            keypad(stdscr, true);
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
            clear();
            refresh();
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
            refresh();
            return (0);
        }
    }

    namespace graphics
    {
        Window::Window()
        {
            FPS = 60;
            _redraw = true;
            if(!al_init()){
                //Todo:: throw exception
            }
            timer = al_create_timer(0.9);
            if(!timer) {
                //Todo::throw exception
            }
            al_init_font_addon(); // initialize the font addon
            al_init_ttf_addon();// initialize the ttf (True Type Font) addon
            display = al_create_display(640,800);
            event_queue = NULL;

            font = al_load_ttf_font("OpenSans-Regular.ttf",14,0 );
            if (!font){
                //Todo::throw exception
                al_destroy_timer(timer);
            }
            if (!display){
                //Todo::throw exception
                al_destroy_timer(timer);
            }
            event_queue = al_create_event_queue();
            if (!event_queue)
            {
                //Todo::throw exception
                al_destroy_display(display);
                al_destroy_timer(timer);
            }
            al_register_event_source(event_queue, al_get_display_event_source(display));
            al_register_event_source(event_queue, al_get_timer_event_source(timer));
            al_clear_to_color(al_map_rgb(50,10,70));
            al_flip_display();
        }

        Window::~Window()
        {
            al_destroy_display(display);
            al_destroy_event_queue(event_queue);
            al_destroy_timer(timer);
        }

        std::vector<module::IMonitorModule *> Window::getModules() { return _modules; }
        void Window::setModules(std::vector < module::IMonitorModule * > mods)
        {
            _modules = mods;
        }

        int Window::updateDisplay()
        {
            float count = 20.0;
            al_clear_to_color(al_map_rgb(50,10,70));
            al_draw_text(font, al_map_rgb(255,255,255), 640/2, (0),ALLEGRO_ALIGN_CENTRE, "System Monitor");
            std::vector<module::IMonitorModule*>::iterator module, end;
            count += 30;

            for(module = _modules.begin(), end = _modules.end(); module != end; module++)
            {
                std::vector<std::string>::iterator str;
                std::vector<std::string> vals = (*module)->getValues();

                al_draw_text(font, al_map_rgb(255,255,255), 640/2, (count/1),ALLEGRO_ALIGN_CENTRE, (*module)->getModuleName().c_str());
                count += 22.0;
                for (str = vals.begin(); str != vals.end(); str++)
                {
                    al_draw_text(font, al_map_rgb(255,255,255), 640/2, (count/1),ALLEGRO_ALIGN_CENTRE, str->c_str());
                    count+=20.0;
                }
                count += 30.0;
            }
            al_flip_display();
            return 0;
        }
    }
}