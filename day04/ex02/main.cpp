#include "ISpaceMarine.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "Squad.hpp"

int main()
{
    ISpaceMarine* bob = new TacticalMarine;
    ISpaceMarine* jim = new AssaultTerminator;
    ISquad* vlc = new Squad;
    std::cout << "pushing object..." << std::endl;
    vlc->push(bob);
    vlc->push(bob);
    vlc->push(bob);
    vlc->push(bob);
    std::cout << "attempted pushing same object 4 times. List count: " << vlc->getCount() << std::endl;
    vlc->push(jim);
    std::cout << "pushed different object. List count: " << vlc->getCount() << std::endl;
    std::cout << "attacks..." << std::endl;
    for (int i = 0; i < vlc->getCount(); ++i)
    {
        ISpaceMarine* cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }

    std::cout << "searching for invalid entry in list..." << std::endl;
    std::cout << vlc->getUnit(7) << std::endl;
    std::cout << "deleting squad" << std::endl;
    delete vlc;
    return 0;
}