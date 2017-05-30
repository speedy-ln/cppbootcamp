#include "Converter.hpp"
#include <iomanip>

int                             main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: example ./convert 0" << std::endl;
        return (0);
    }

    Converter      convert(av[1]);

    //Char
    std::cout << "char: ";
    try {
        std::cout << static_cast<char>(convert) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    //Int
    std::cout << "int: ";
    try {
        std::cout << static_cast<int>(convert) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    //float
    std::cout << std::fixed;
    std::cout.precision(1);
    std::cout << "float: ";
    try {
        std::cout << static_cast<float>(convert) << 'f' << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    //double
    std::cout << "double: ";
    try {
        std::cout << static_cast<double>(convert) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
