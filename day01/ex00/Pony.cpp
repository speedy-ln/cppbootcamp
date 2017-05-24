#include "Pony.hpp"

std::string Pony::getName() { return this->name; }
void Pony::setName(std::string name) { this->name = name; }
Pony::~Pony() {
    std::cout << "Killing " << this->getName() << " now :(" << std::endl;
}
