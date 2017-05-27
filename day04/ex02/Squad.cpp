#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

Squad::Squad() :list(NULL) {}
Squad::~Squad()
{
    struct _sUnit *tmp = list;
    while (list != NULL)
    {
        delete list->marine;
        list = list->next;
        if (!list)
            delete tmp;
    }
}
Squad::Squad(Squad const &copy) { *this = copy; }
Squad& Squad::operator=(Squad const &copy)
{
    list = copy.list;
    return *this;
}


int Squad::getCount() const
{
    int count = 0;
    struct _sUnit *tmp = list;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

ISpaceMarine* Squad::getUnit(int n) const
{
    struct _sUnit *tmp = list;
    while (tmp)
    {
        if (n == tmp->index)
            return tmp->marine;
        tmp = tmp->next;
    }
    return NULL;
}

int Squad::push(ISpaceMarine *unit)
{
    if (unit) {
        struct _sUnit *newUnit = new _sUnit();
        struct _sUnit *first = list;
        newUnit->marine = unit;
        newUnit->next = NULL;

        if(list == NULL)
        {
            newUnit->index = 0;
            list = newUnit;
            return getCount();
        }
        if (list->marine == unit)
        {
            list = first;
            return getCount();
        }
        while (list->next) {
            if (list->marine == unit)
            {
                list = first;
                return getCount();
            }
            list = list->next;
        }
        newUnit->index = list->index + 1;
        list->next = newUnit;
        list = first;
    }
    return getCount();
}