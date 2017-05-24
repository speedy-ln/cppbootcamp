#include "Brain.hpp"

Brain::Brain()
{
    std::ostringstream os;
    os << std::hex << this;
    this->address = os.str();
}

std::string Brain::identify() const
{
    return this->address;
}