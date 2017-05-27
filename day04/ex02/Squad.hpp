#ifndef SQUAD_HPP
#define SQUAD_HPP

#include "ISquad.hpp"

class Squad : public ISquad
{
public:
    Squad();
    ~Squad();
    Squad(Squad const &copy);
    Squad &operator=(Squad const &copy);

    int             getCount() const;
    ISpaceMarine    *getUnit(int n) const;
    int             push(ISpaceMarine *unit);

private:
    struct _sUnit
    {
        int index;
        ISpaceMarine *marine;
        struct _sUnit *next;
    };
    struct _sUnit *list;

};

#endif