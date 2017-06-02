#ifndef IMONITOR_DISPLAY_HPP
#define IMONITOR_DISPLAY_HPP

#include "RushIncluces.hpp"

namespace module
{
    class IMonitorDisplay
    {
    public:
        IMonitorDisplay();
        virtual ~IMonitorDisplay();



    private:
        IMonitorDisplay &operator=(IMonitorDisplay const &copy);
        IMonitorDisplay(IMonitorDisplay const &copy);
    };
}

#endif