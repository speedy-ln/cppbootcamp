#ifndef CPPBOOTCAMP_RUSHTEMPLATES_H
#define CPPBOOTCAMP_RUSHTEMPLATES_H

namespace templates
{
    template <typename T> std::string tostr(const T& t) {
        std::ostringstream os;
        os << t;
        return os.str();
    }
}

#endif
