#ifndef CPPBOOTCAMP_LINE_H
#define CPPBOOTCAMP_LINE_H

#include "../IMonitorDisplay.hpp"

namespace display
{
    namespace text
    {
        class Line
        {
        public:
            Line(int width);
            ~Line();

            void        setCustom(std::string centralText);
            std::string getCenteredText(std::string centralText);

            std::string top;
            std::string filler;
            std::string blank;
            std::string custom;

        private:
            int     _width;
            Line();
            Line(Line const &line);
            Line &operator=(Line const &line);
        };
    }
}

#endif
