#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>
# include <string>

class Pony {
public:
    ~Pony();
    std::string getName();
    void        setName(std::string name);
private:
    std::string name;
};

#endif