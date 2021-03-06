#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::~ZombieEvent()
{
    std::cout << "Killing the zombie on the heap" << std::endl;
}

 void ZombieEvent::setZombieType(std::string type) {
     this->ZombieType = type;
 }

Zombie*  ZombieEvent::newZombie(std::string name) {
    Zombie *zombie = new Zombie();
    zombie->setName(name);
    zombie->setType(this->ZombieType);
    return zombie;
}

