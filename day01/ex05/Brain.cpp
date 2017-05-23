#include "Brain.hpp"

Brain::Brain()
{
    const volatile std::string address = "";
    std::ostringstream os;
    os << std::hex << this;
    std::string &modify_address = const_cast<std::string &> (address);
    modify_address = os.str();
    this->address = modify_address;
}

std::string Brain::identify() const
{
    return this->address;
}