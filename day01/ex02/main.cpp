#include "ZombieEvent.hpp"
#include "Zombie.hpp"

std::string randomName()
{
    std::string names[10];
    names[0] = "James";
    names[1] = "John";
    names[2] = "Joel";
    names[3] = "Sandy";
    names[4] = "Mac man";
    names[5] = "Ronald Mc Donald";
    names[6] = "Spader";
    names[7] = "Retrogade";
    names[8] = "Bra Zab";
    names[9] = "Sfiso";
    return (names[(time(NULL) % 9)]);
}

void        randomChump()
{
    ZombieEvent event = ZombieEvent();
    event.setZombieType("Runner");
    Zombie *zombie = event.newZombie(randomName());
    zombie->announce();
}

int         main()
{
    randomChump();
    Zombie zombie = Zombie();
    zombie.setName(randomName());
    zombie.setType("Dry");
    zombie.announce();
    return (0);
}