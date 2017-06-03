#include "Line.hpp"

namespace display
{
    namespace text
    {
        Line::Line(int width)
        {
            std::stringstream s_filler, s_top, s_blank;
            _width = width;
            for (int i = 0; i < width; ++i)
            {
                s_top << "-";
                if (i == 0 || i == 29)
                {
                    s_filler << "|";
                    s_blank << "|";
                }
                else
                {
                    s_blank << " ";
                    s_filler << ".";
                }
            }
            s_top << std::endl;
            s_filler << std::endl;
            s_blank << std::endl;
            top = s_top.str();
            filler = s_filler.str();
            blank = s_blank.str();
        }
        Line::~Line() {}

        void Line::setCustom(std::string centralText)
        {
            int len = centralText.size();
            int offset;
            if (len > _width)
                centralText = centralText.substr(0, _width - 2);
            offset = (_width - centralText.size()) / 2;
            std::ostringstream os;
            os << "|";
            for (int i = 1; i < offset; ++i) {
                os << "." ;
            }
            os << centralText;
            for (int j = 1; j < offset; ++j) {
                os << ".";
            }
            os << "|" << std::endl;
            custom = os.str();
        }

        std::string Line::getCenteredText(std::string centralText)
        {
            int len = centralText.size();
            int offset;
            if (len > _width)
                centralText = centralText.substr(0, _width - 2);
            offset = (_width - centralText.size()) / 2;
            std::ostringstream os;
            os << "|";
            for (int i = 1; i < offset; ++i) {
                os << "." ;
            }
            os << centralText;
            for (int j = 1; (j < offset); ++j) {
                os << ".";
            }
//            while (os.str().size() != static_cast<unsigned long>(_width))
//                os << ".";
            os << "|" << std::endl;
            return os.str();
        }
    }
}