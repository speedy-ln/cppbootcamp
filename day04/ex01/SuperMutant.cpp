#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant") { std::cout << "Gaaah. Me want smash heads !" << std::endl; }
SuperMutant::~SuperMutant() { std::cout << "Aaargh ..." << std::endl; }
SuperMutant::SuperMutant(SuperMutant const &copy) : Enemy(170, "Super Mutant") { *this = copy; std::cout << "Gaaah. Me want smash heads !" << std::endl;}
SuperMutant& SuperMutant::operator=(SuperMutant const &copy)
{
    if (this != &copy)
        Enemy::operator=(copy);
    return (*this);
}

void SuperMutant::takeDamage(int damage) { if(_hp > 0 && damage > 3) _hp -= (damage - 3); }