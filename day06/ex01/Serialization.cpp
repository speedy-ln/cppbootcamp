#include "Serialization.hpp"

Serialization::Serialization() { srand(time(NULL)); }
Serialization::~Serialization() {}
Serialization::Serialization(Serialization const &copy)
{
    srand(time(NULL));
    *this = copy;
}
Serialization& Serialization::operator=(Serialization const &copy) { (void)copy; return (*this); }

void* Serialization::serialize()
{
    Data *data = new Data();
    data->s1 = "";
    data->s2 = "";
    data->n = rand();;
    std::string alphaNum = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < 8; i++)
        data->s1 += alphaNum.at(rand() % 61);
    for (int i = 0; i < 8; i++)
        data->s2 += alphaNum.at(rand() % 61);
    return reinterpret_cast<void *>(data);
}

Serialization::Data* Serialization::deserialize(void *raw)
{
    Data * data = reinterpret_cast<Data *>(raw);
    return data;
}