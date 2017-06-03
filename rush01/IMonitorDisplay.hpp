#ifndef IMONITOR_DISPLAY_HPP
#define IMONITOR_DISPLAY_HPP

#include "RushIncluces.hpp"

namespace display
{
    class IMonitorDisplay
    {
    public:
        IMonitorDisplay();
        virtual ~IMonitorDisplay();

        virtual int updateDisplay() = 0;

    private:
        IMonitorDisplay &operator=(IMonitorDisplay const &copy);
        IMonitorDisplay(IMonitorDisplay const &copy);
    };
}

#endif