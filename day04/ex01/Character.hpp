#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
public:
    Character(std::string const &name);
    ~Character();
    Character(Character const &copy);
    Character   &operator=(Character const &copy);

    void                recoverAP();
    void                equip(AWeapon *weapon);
    void                attack(Enemy *enemy);
    std::string const   &getName() const;
    int                 getAP() const;
    AWeapon const       *getWeapon() const;

private:
    Character();
    std::string   _name;
    int                 _ap;
    AWeapon             *_weapon;
};

std::ostream    &operator<<(std::ostream &os, Character const &copy);

#endif