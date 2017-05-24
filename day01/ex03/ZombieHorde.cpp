#include "ZombieHorde.hpp"

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
    return (names[(rand() % 9)]);
}

ZombieHorde::ZombieHorde(int N)
{
    zombie = new Zombie[N];
    num_zombies = N;
    for (int i = 0; i < N; ++i) {
        zombie[i].setType("Runner");;
        zombie[i].setName(randomName());
    }
}

ZombieHorde::~ZombieHorde() { delete [] zombie; }

void ZombieHorde::announce()
{
    for (int i = 0; i < num_zombies; ++i)
        zombie[i].announce();
}