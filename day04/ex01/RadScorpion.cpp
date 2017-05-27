#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion") { std::cout << "* click click click *" << std::endl; }
RadScorpion::~RadScorpion() { std::cout << "* SPROTCH *" << std::endl; }
RadScorpion::RadScorpion(RadScorpion const &copy) : Enemy(80, "RadScorpion") { *this = copy; std::cout << "* click click click *" << std::endl; }
RadScorpion& RadScorpion::operator=(RadScorpion const &copy)
{
    if (this != &copy)
        Enemy::operator=(copy);
    return (*this);
}