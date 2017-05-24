#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
public:
    ~Zombie();

    void        announce();
    void        setName(std::string name);
    std::string getName();
    std::string getType();
    void        setType(std::string type);

private:
    std::string name;
    std::string type;
};

#endif