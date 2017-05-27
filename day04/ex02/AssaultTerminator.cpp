#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator() { std::cout << "* teleports from space *" << std::endl; }
AssaultTerminator::~AssaultTerminator() { std::cout << "I’ll be back ..." << std::endl; }
AssaultTerminator::AssaultTerminator(AssaultTerminator const &copy) { *this = copy; std::cout << "* teleports from space *" << std::endl; }
AssaultTerminator& AssaultTerminator::operator=(AssaultTerminator const &copy)
{
    if(this != &copy) {}
    return *this;
}


ISpaceMarine* AssaultTerminator::clone() const { return (new AssaultTerminator()); }
void AssaultTerminator::rangedAttack() const { std::cout << "* does nothing *" << std::endl; }
void AssaultTerminator::battleCry() const { std::cout << "This code is unclean. PURIFY IT !" << std::endl; }
void AssaultTerminator::meleeAttack() const { std::cout << "* attacks with chainfists *" << std::endl; }