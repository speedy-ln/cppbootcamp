#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>
#include <iostream>

class Enemy
{
public:
    Enemy(int hp, std::string const &type);
//    ~Enemy();
    virtual ~Enemy() = 0;
    Enemy(Enemy const &copy);
    Enemy               &operator=(Enemy const &copy);

    int                 getHP() const;
    std::string const   &getType() const;
    virtual void        takeDamage(int damage);

protected:
    int         _hp;
    std::string _type;
};

#endif