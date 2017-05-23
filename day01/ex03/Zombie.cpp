#include "Zombie.hpp"

void Zombie::announce()
{
    std::cout << "<" << this->name << " (" << this->type << ")> Braiiiiiiinnnssss..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Killing the zombie on the stack" << std::endl;
}