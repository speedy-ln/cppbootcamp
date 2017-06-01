#include <iostream>
#include <string>

template<typename T>
void    iter(T *arr, size_t len, void (*func)(T const &)) { for (size_t i = 0; i < len; i++) func(arr[i]); }

template<typename T>
void    print(T &prnt) { std::cout << prnt << std::endl; }

int main(void)
{
    int integer_arr[] = {1, 2, 3, 4, 5};
    std::string string_arr[] = {"dab", "dab again", "another one", "good job"};

    std::cout << "Integer array: "<< std::endl;
    iter(integer_arr, 5, print);
    std::cout << "String array: "<< std::endl;
    iter(string_arr, 4, print);

    return (0);
}