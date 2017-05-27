#ifndef TACTICAL_MARINE_HPP
#define TACTICAL_MARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
public:
    TacticalMarine();
    ~TacticalMarine();
    TacticalMarine(TacticalMarine const &copy);
    TacticalMarine  &operator=(TacticalMarine const &copy);

    ISpaceMarine*   clone() const;
    void            battleCry() const;
    void            rangedAttack() const;
    void            meleeAttack() const;
};

#endif