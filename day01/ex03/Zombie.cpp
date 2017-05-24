#include "Zombie.hpp"

void Zombie::announce()
{
    std::cout << "<" << this->getName() << " (" << this->getType() << ")> Braiiiiiiinnnssss..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Killing the zombie on the stack" << std::endl;
}

void Zombie::setName(std::string name) { this->name = name; }
void Zombie::setType(std::string type) { this->type = type; }
std::string Zombie::getName() { return this->name; }
std::string Zombie::getType() { return this->type; }