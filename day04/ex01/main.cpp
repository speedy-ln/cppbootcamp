#include "Character.hpp"
#include "RadScorpion.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"

int main()
{
    //PDF Tests
    Character* zaz = new Character("zaz");
    std::cout << *zaz;
    Enemy* b = new RadScorpion();
    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();
    zaz->equip(pr);
    std::cout << *zaz;
    zaz->equip(pf);
    zaz->attack(b);
    std::cout << *zaz;
    zaz->equip(pr);
    std::cout << *zaz;
    zaz->attack(b);
    std::cout << *zaz;
    zaz->attack(b);
    std::cout << *zaz;

    //My test
    /*
    Character		*zaz = new Character("zaz");
    PlasmaRifle		*pr = new PlasmaRifle();
    PowerFist		*pf = new PowerFist();
    SuperMutant		*sm = new SuperMutant();
    RadScorpion		*rs = new RadScorpion();

    std::cout << *zaz;
    zaz->equip(pr);
    std::cout << *zaz;
    zaz->equip(pf);
    zaz->attack(rs);
    std::cout << *zaz;
    zaz->equip(pr);
    std::cout << *zaz;
    zaz->attack(rs);
    std::cout << *zaz;
    zaz->attack(rs);
    std::cout << *zaz;
    zaz->attack(sm);
    std::cout << *zaz;
    SuperMutant	sm2 = *sm;
    */

    return 0;
}