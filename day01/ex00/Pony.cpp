#include "Pony.hpp"

Pony::~Pony() {
    std::cout << "Killing " << this->name << " now :(" << std::endl;
}
