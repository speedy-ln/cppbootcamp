#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <iostream>
#include <string>

class FragTrap
{
public:
    FragTrap(std::string name);
    ~FragTrap();
    FragTrap(const FragTrap &copy);
    FragTrap        &operator=(FragTrap const copy);

    void            setHitPoints(int amount);
    void            setEnergyPoints(unsigned int amount);
    void            setLevel(int level);
    void            setName(std::string name);

    unsigned int    meleeAttackDamage;
    unsigned int    rangedAttackDamage;

    unsigned int    getHitPoints() const;
    unsigned int    getEnergyPoints() const;
    unsigned int    getLevel() const;
    unsigned int    getArmourDamageReduction() const;
    std::string     getName() const;
    int             remainingEnergyPoints(unsigned int damage);

    void            rangedAttack(std::string const & target);
    void            meleeAttack(std::string const & target);
    void            takeDamage(unsigned int amount);
    void            beRepaired(unsigned int amount);
    int             vaulthunter_dot_exe(std::string const & target);
    void            neckSnap(std::string const target);
    void            lazerBlast(std::string const target);
    void            finishHim(std::string const target);
    void            doDamage(std::string const target);
    void            killerCombo(std::string const target);

private:
    int    maxHitPoints;
    unsigned int    maxEnergyPoints;
    unsigned int    armourDamageReduction;
    unsigned int    hitPoints;
    unsigned int    energyPoints;
    unsigned int    level;
    std::string     name;
};

std::ostream & operator<<(std::ostream & o, FragTrap const &copy);

#endif