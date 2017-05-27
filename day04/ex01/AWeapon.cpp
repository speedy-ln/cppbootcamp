#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage) : _name(name), _apcost(apcost), _damage(damage) {}
AWeapon::~AWeapon() {}
AWeapon::AWeapon(AWeapon const &copy) { *this = copy; }
AWeapon& AWeapon::operator=(AWeapon const &copy)
{
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_apcost = copy._apcost;
        this->_damage = copy._damage;
    }
    return (*this);
}

std::string const & AWeapon::getName() const { return _name; }
int AWeapon::getAPCost() const { return _apcost; }
int AWeapon::getDamage() const { return _damage; }