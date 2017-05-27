#ifndef ASSAULT_TERMINATOR_HPP
#define ASSAULT_TERMINATOR_HPP

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
public:
    AssaultTerminator();
    ~AssaultTerminator();
    AssaultTerminator(AssaultTerminator const &copy);
    AssaultTerminator &operator=(AssaultTerminator const &copy);

    ISpaceMarine*   clone() const;
    void            battleCry() const;
    void            rangedAttack() const;
    void            meleeAttack() const;
};

#endif