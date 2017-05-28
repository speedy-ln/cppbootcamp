#ifndef POWER_FIST_HPP
#define POWER_FIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
    PowerFist();
    ~PowerFist();
    PowerFist(PowerFist const &copy);
    PowerFist   &operator=(PowerFist const &copy);

    void        attack() const;

private:
    std::string _name;
};

#endif