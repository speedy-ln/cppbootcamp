#include "Human.hpp"

Human::Human() : brain() {}

Human::~Human() {}

std::string Human::identify() const
{
    return brain.identify();
}

Brain Human::getBrain()
{
    return brain;
}