#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP

#include "Zombie.hpp"

class ZombieHorde
{
public:
    Zombie  *zombie;
    int     num_zombies;
    ZombieHorde(int N);
    ~ZombieHorde();
    void    announce();
};

#endif