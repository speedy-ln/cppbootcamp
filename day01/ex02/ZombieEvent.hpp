#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

#include "Zombie.hpp"

class ZombieEvent {
public:
    ~ZombieEvent();
    void        setZombieType(std::string type);
    Zombie*     newZombie(std::string name);

private:
    std::string ZombieType;
};

std::string     randomName();
void            randomChump();

#endif