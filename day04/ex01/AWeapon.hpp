#ifndef A_WEAPON_HPP
#define A_WEAPON_HPP

#include <string>
#include <iostream>

class AWeapon
{
public:
    AWeapon(std::string const &name, int apcost, int damage);
    ~AWeapon();
    AWeapon(AWeapon const &copy);
    AWeapon &operator=(AWeapon const &copy);

    std::string const &    getName() const;
    int             getAPCost() const;
    int             getDamage() const;
    virtual void    attack() const = 0;

private:
    AWeapon();
    std::string _name;
    int         _apcost;
    int         _damage;
};

std::ostream &operator<<(std::ostream & o, AWeapon const &copy);

#endif