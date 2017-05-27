#include "Enemy.hpp"

Enemy::Enemy(int hp, const std::string &type) : _hp(hp), _type(type) {}
Enemy::~Enemy() {}
Enemy::Enemy(Enemy const &copy) { *this = copy; }
Enemy& Enemy::operator=(Enemy const &copy)
{
    if (this != &copy)
    {
        _type = copy._type;
        _hp = copy._hp;
    }
    return (*this);
}


int Enemy::getHP() const { return _hp; }
std::string const & Enemy::getType() const { return _type; }
void Enemy::takeDamage(int damage)
{
    if (damage > 0) _hp -= damage;
}