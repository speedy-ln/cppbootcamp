#include "Serialization.hpp"

int main(void)
{
    Serialization s1;

    void *v1;
    Serialization::Data *d1;

    v1 = s1.serialize();
    d1 = s1.deserialize(v1);

    std::cout << d1->s1 << std::endl;
    std::cout << d1->n << std::endl;
    std::cout << d1->s2 << std::endl;

    delete d1;
    return (0);
}