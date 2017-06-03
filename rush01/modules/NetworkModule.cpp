#include "NetworkModule.hpp"

namespace module
{
    NetworkModule::NetworkModule(std::string moduleName)
    {
        _moduleName = moduleName;
        setModuleValue();
    }

    NetworkModule::~NetworkModule() {}

    void NetworkModule::setModuleValue()
    {
        _moduleValue.resize(2);
        int mib[] = { CTL_NET, PF_ROUTE, 0, 0, NET_RT_IFLIST2, 0 };
        size_t len;
        if (sysctl(mib, 6, NULL, &len, NULL, 0) < 0)
            return;
        char buf[len];
        if (sysctl(mib, 6, buf, &len, NULL, 0) < 0)
            return;
        char *lim = buf + len;
        char *next = NULL;
        u_int64_t totalibytes = 0;
        u_int64_t totalobytes = 0;
        for (next = buf; next < lim; ) {
            struct if_msghdr *ifm = (struct if_msghdr *)next;
            next += ifm->ifm_msglen;
            if (ifm->ifm_type == RTM_IFINFO2) {
                struct if_msghdr2 *if2m = (struct if_msghdr2 *)ifm;
                totalibytes += if2m->ifm_data.ifi_ibytes;
                totalobytes += if2m->ifm_data.ifi_obytes;
            }
        }
        _moduleValue[0] = "Data received: " + templates::tostr(totalibytes/1048576) + "MB";
        _moduleValue[1] = "Data sent: " + templates::tostr(totalobytes/1048576) + "MB";
    }

    std::string NetworkModule::getModuleValue()
    {
        return "Data received: " + _moduleValue[0] + "Mb Data sent: " + _moduleValue[1] + "Mb";
    }


}