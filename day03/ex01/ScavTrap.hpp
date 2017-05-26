#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

class ScavTrap{

public:
    ScavTrap(void);
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &copy );
    ScavTrap& operator=( ScavTrap const &copy );
    ~ScavTrap();

    void            rangedAttack(std::string const & target);
    void            meleeAttack(std::string const & target);
    void            takeDamage(unsigned int amount);
    void            beRepaired(unsigned int amount);

    void            setHitPoints(int amount);
    void            setEnergyPoints(unsigned int amount);
    void            setLevel(int level);
    void            setName(std::string name);

    unsigned int    getHitPoints() const;
    unsigned int    getEnergyPoints() const;
    unsigned int    getLevel() const;
    unsigned int    getArmourDamageReduction() const;
    std::string     getName() const;

    int             remainingEnergyPoints(unsigned int damage);
    void            pissingContest(std::string const target);
    void            challengeNewcomer(const std::string &target);
    void            mexicanStandOff(std::string const target);

    unsigned int    meleeAttackDamage;
    unsigned int    rangedAttackDamage;


private:
    int    maxHitPoints;
    unsigned int    maxEnergyPoints;
    unsigned int    armourDamageReduction;
    unsigned int    hitPoints;
    unsigned int    energyPoints;
    unsigned int    level;
    std::string     name;

};

std::ostream & operator<<(std::ostream & o, ScavTrap const &copy);

#endif