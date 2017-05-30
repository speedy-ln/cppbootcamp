#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Serialization
{
public:
    Serialization();
    ~Serialization();
    Serialization(Serialization const &copy);
    Serialization &operator=(Serialization const &copy);

    struct Data {
        std::string s1;
        int         n;
        std::string s2;
    } typedef Data;

    void    *serialize(void);
    Data    *deserialize(void * raw);

};

#endif