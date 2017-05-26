#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
    setName(name);
    hitPoints = 100;
    maxHitPoints = 100;
    energyPoints = 50;
    maxEnergyPoints = 50;
    setLevel(1);
    meleeAttackDamage = 20;
    rangedAttackDamage = 15;
    armourDamageReduction = 3;
    std::cout << "Claptrap -- start bootup sequence complete... " << name << ": Feels good to be alive" << std::endl;
}

ScavTrap::~ScavTrap() { std::cout << "This is my last breath... Avenge my death!" << std::endl; }

ScavTrap::ScavTrap(ScavTrap const &copy) { *this = copy; }

ScavTrap& ScavTrap::operator=(ScavTrap const &copy)
{
    std::cout << "Bootup sequence complete... Please adjust factory settings to meet your needs before deployment." << std::endl;
    if (this != &copy)
    {
        name = copy.getName();
        hitPoints = copy.getHitPoints();
        maxHitPoints = copy.maxHitPoints;
        energyPoints = copy.getEnergyPoints();
        maxEnergyPoints = copy.maxEnergyPoints;
        level = copy.getLevel();
        meleeAttackDamage = copy.meleeAttackDamage;
        rangedAttackDamage = copy.rangedAttackDamage;
        armourDamageReduction = copy.getArmourDamageReduction();
    }
    return (*this);
}

unsigned int ScavTrap::getLevel() const { return level; }
std::string ScavTrap::getName() const { return name; }
unsigned int ScavTrap::getArmourDamageReduction() const { return armourDamageReduction; }
unsigned int ScavTrap::getEnergyPoints() const { return energyPoints; }
unsigned int ScavTrap::getHitPoints() const { return hitPoints; }

std::ostream& operator<<(std::ostream &o, ScavTrap const &copy) {
    ScavTrap obj(copy);
    o << obj.getName();
    return o;
}

int ScavTrap::remainingEnergyPoints(unsigned int damage) { return (getEnergyPoints() - damage); }

void ScavTrap::setHitPoints(int amount)
{
    if (amount >= maxHitPoints)
        hitPoints = maxHitPoints;
    else if (amount <= 0)
        hitPoints = 0;
    else
        hitPoints = (unsigned int) amount;
}

void ScavTrap::setName(std::string nm) { name = nm; }
void ScavTrap::setLevel(int lvl) { level = lvl; }

void ScavTrap::setEnergyPoints(unsigned int amount)
{
    if (amount >= maxEnergyPoints)
        energyPoints = maxEnergyPoints;
    else if (amount <= 0)
        energyPoints = 0;
    else
        energyPoints = amount;
}


void ScavTrap::beRepaired(unsigned int amount)
{
    int remainingHealth = getHitPoints() + amount;
    setHitPoints(remainingHealth);
    std::cout << "Sweet life juice! " << name << " replinished health to " << getHitPoints() << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    int remainingHealth = getHitPoints() - amount;
    amount -= armourDamageReduction;
    setHitPoints(remainingHealth);
    std::cout << "Why do I even feel pain?! " << getName() << " took " << amount <<
              " damage and has " << getHitPoints() << "hit points left." <<std::endl; ;
}

void ScavTrap::rangedAttack(const std::string &target)
{
    std::cout << "FR4G-TP <" << getName() << "> attacks <"
              << target << "> at range, causing <" << armourDamageReduction << "> points of damage !" << std::endl;
}

void ScavTrap::meleeAttack(const std::string &target)
{
    std::cout << "FR4G-TP <" << getName() << "> attacks <"
              << target << "> at range, causing <" << meleeAttackDamage << "> points of damage !" << std::endl;
}

void ScavTrap::pissingContest(std::string const target) {
    std::cout << name << " Challenges " << target << " to a pissing contest "<< std::endl;

    std::cout << "They both take out their weapons" << std::endl;
    srand(time(0));
    int random = (rand() % 2);
    if (random == 1) {
        std::cout << name << " is too quick and gets " << target << "!! :O" << std::endl;
    }
    else {
        std::cout << target << " pissing on " << name << ". :|" << std::endl;
    }
}
void ScavTrap::mexicanStandOff(std::string const target) {
    std::cout << name << " Challenges " << target << " to a mexican stand off "<< std::endl;

    std::cout << "They both take up their positions, ready to shoot..." << std::endl;
    srand(time(0));
    int random = (rand() % 2);
    if (random == 1) {
        std::cout << target << " is too quick and shoots " << name << " up!! :O" << std::endl;
    }
    else {
        std::cout << name << " shoots " << target << ". :|" << std::endl;
    }
}

void ScavTrap::challengeNewcomer(const std::string &target)
{
    int random;

    srand(time(0));
    random = (int)(floor( 2 * rand() ));
    if (random == 1) {
        pissingContest(target);
    }
    else {
        mexicanStandOff(target);
    }
}
