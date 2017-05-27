#ifndef RAD_SCORPION_HPP
#define RAD_SCORPION_HPP

#include "Enemy.hpp"

class RadScorpion :public Enemy
{
public:
    RadScorpion();
    ~RadScorpion();
    RadScorpion(RadScorpion const &copy);
    RadScorpion &operator=(RadScorpion const &copy);
};

#endif