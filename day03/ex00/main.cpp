#include "FragTrap.hpp"

int				main(void)
{
    FragTrap	hulk("Hulk");
    FragTrap	Kong("Kong");

    hulk.rangedAttack("Kong");
    Kong.takeDamage(hulk.rangedAttackDamage);

    Kong.meleeAttack("Hulk");
    hulk.takeDamage(Kong.meleeAttackDamage);

    hulk.meleeAttack("Kong");
    Kong.takeDamage(hulk.meleeAttackDamage);

    Kong.rangedAttack("Hulk");
    hulk.takeDamage(Kong.meleeAttackDamage);

    Kong.beRepaired(50);

    Kong.rangedAttack("Hulk");
    hulk.takeDamage(Kong.rangedAttackDamage);

    hulk.takeDamage(Kong.vaulthunter_dot_exe("Hulk"));
    hulk.takeDamage(Kong.vaulthunter_dot_exe("Hulk"));
    hulk.takeDamage(Kong.vaulthunter_dot_exe("Hulk"));
    hulk.takeDamage(Kong.vaulthunter_dot_exe("Hulk"));

    Kong.takeDamage(200);
}