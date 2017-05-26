#include "FragTrap.hpp"



FragTrap::FragTrap(std::string name)
{
    setName(name);
    hitPoints = 100;
    maxHitPoints = 100;
    energyPoints = 100;
    maxEnergyPoints = 100;
    setLevel(1);
    meleeAttackDamage = 30;
    rangedAttackDamage = 20;
    armourDamageReduction = 5;
    std::cout << "Claptrap -- start bootup sequence complete... " << name << ": Feels good to be alive" << std::endl;
}

void FragTrap::setLevel(int lvl) { level = lvl; }
void FragTrap::setName(std::string theName) { name = theName; }

FragTrap::~FragTrap() { std::cout << "This is my last breath... Avenge my death!" << std::endl; }

FragTrap::FragTrap(const FragTrap &copy)
{
    std::cout << "You. Are. Not. Dead! Now shut the hell up! Your new designation is FR4G-TP. Fragtrap. You are a merciless killing machine. Got it?" << std::endl;
    *this = copy;
}

FragTrap& FragTrap::operator=(FragTrap const copy)
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

std::ostream& operator<<(std::ostream &o, FragTrap const &copy) {
    FragTrap obj(copy);
    o << obj.getName();
    return o;
}

unsigned int FragTrap::getHitPoints() const { return hitPoints; }
unsigned int FragTrap::getLevel() const { return level; }
std::string FragTrap::getName() const { return name; }
unsigned int FragTrap::getArmourDamageReduction() const { return armourDamageReduction; }
unsigned int FragTrap::getEnergyPoints() const { return energyPoints; }

void FragTrap::rangedAttack(const std::string &target)
{
    std::cout << "FR4G-TP <" << getName() << "> attacks <"
                << target << "> at range, causing <" << armourDamageReduction << "> points of damage !" << std::endl;
}

void FragTrap::meleeAttack(const std::string &target)
{
    std::cout << "FR4G-TP <" << getName() << "> attacks <"
              << target << "> at range, causing <" << meleeAttackDamage << "> points of damage !" << std::endl;
}

int FragTrap::remainingEnergyPoints(unsigned int damage) { return (getEnergyPoints() - damage); }

void FragTrap::setHitPoints(int amount)
{
    if (amount >= maxHitPoints)
        hitPoints = maxHitPoints;
    else if (amount <= 0)
        hitPoints = 0;
    else
        hitPoints = (unsigned int) amount;
}

void FragTrap::setEnergyPoints(unsigned int amount)
{
    if (amount >= maxEnergyPoints)
        energyPoints = maxEnergyPoints;
    else if (amount <= 0)
        energyPoints = 0;
    else
        energyPoints = amount;
}

void FragTrap::takeDamage(unsigned int amount)
{
    int remainingHealth = getHitPoints() - amount;
    amount -= armourDamageReduction;
    setHitPoints(remainingHealth);
    std::cout << "Why do I even feel pain?! " << getName() << " took " << amount <<
              " damage and has " << getHitPoints() << "hit points left." <<std::endl; ;
}

void FragTrap::beRepaired(unsigned int amount)
{
    int remainingHealth = getHitPoints() + amount;
    setHitPoints(remainingHealth);
    std::cout << "Sweet life juice! " << name << " replinished health to " << getHitPoints() << std::endl;
}

int FragTrap::vaulthunter_dot_exe(const std::string &target)
{
    int			random;

    if (getEnergyPoints() >= 25)
    {
        setEnergyPoints((getEnergyPoints() - 25));
        srand(time(0));
        random = (rand() % 4) + 1;
        switch (random) {
            case 1:
                killerCombo(target);
                return (30);
            case 2:
                doDamage(target);
                return (20);
            case 3:
                finishHim(target);
                return (70);
            case 4:
                lazerBlast(target);
                return (8);
            case 5:
                neckSnap(target);
                return (25);
        }
    }
    else
        std::cout << "Energy Too low" << std::endl;
    return (0);
}

void FragTrap::killerCombo(std::string const target) {
    std::cout << "FR4G-TP <" << getName() << "> attacks <"
              << target << "> at range, causing <" << armourDamageReduction << "> points of damage !" << std::endl;
}

void FragTrap::doDamage(std::string const target) {
    std::cout << "FR4G-TP <" << getName() << "> attacks <"
              << target << "> at range, causing <" << armourDamageReduction << "> points of damage !" << std::endl;
}

void FragTrap::finishHim(std::string const target) {
    std::cout << "FR4G-TP <" << getName() << "> attacks <"
              << target << "> at range, causing <" << armourDamageReduction << "> points of damage !" << std::endl;
}

void FragTrap::lazerBlast(std::string const target) {
    std::cout << "FR4G-TP <" << getName() << "> attacks <"
              << target << "> at range, causing <" << armourDamageReduction << "> points of damage !" << std::endl;
}



void FragTrap::neckSnap(std::string const target) {
    std::cout << "FR4G-TP <" << getName() << "> attacks <"
              << target << "> at range, causing <" << armourDamageReduction << "> points of damage !" << std::endl;
}

