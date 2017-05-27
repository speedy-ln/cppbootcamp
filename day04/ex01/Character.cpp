#include "Character.hpp"

Character::Character(const std::string &name) : _name(name), _ap(40), _weapon(NULL) {}
Character::~Character() {}
Character::Character(Character const &copy) : _name(copy._name) { *this = copy; }
Character& Character::operator=(Character const &copy)
{
    if (this != &copy)
        *this = copy;
    return (*this);
}


int                 Character::getAP() const { return _ap; }
std::string const & Character::getName() const { return _name; }
AWeapon const       *Character::getWeapon() const { return _weapon; }

void    Character::attack(Enemy *enemy)
{
    if (_weapon)
    {
        if (_weapon->getAPCost() < _ap)
        {
            std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;
            _weapon->attack();
            enemy->takeDamage(_weapon->getDamage());
            if (enemy->getHP() <= 0) delete enemy;
            _ap -= _weapon->getAPCost();
        }
    }
}
void    Character::equip(AWeapon *weapon) { _weapon = weapon; }
void    Character::recoverAP()
{
    if(_ap <= 30) _ap += 10;
    else if (_ap > 30 && _ap < 40) _ap = 40;
}

std::ostream    &operator<<(std::ostream &os, Character const &copy)
{
    os << copy.getName() << " has " << copy.getAP() << " AP and ";
    if (copy.getWeapon()) os << "wields a " << copy.getWeapon()->getName() << std::endl;
    else os << "is unarmed" << std::endl;
    return (os);
}