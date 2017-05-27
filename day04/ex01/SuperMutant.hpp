#ifndef SUPER_MUTANT_HPP
#define SUPER_MUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
    SuperMutant();
    ~SuperMutant();
    SuperMutant(SuperMutant const &copy);
    SuperMutant     &operator=(SuperMutant const &copy);

    virtual void    takeDamage(int damage);
};

#endif