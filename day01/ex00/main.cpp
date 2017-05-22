#include "Pony.hpp"

void	ponyOnTheHeap()
{
    Pony*   pony = new Pony();
    std::cout << "You see a cute pony... Give it a name: " ;
    std::cin >> pony->name;
    std::cout << "Your pony " << pony->name << " is sick" << std::endl;
    delete pony;
    std::cout << std::endl;
}

void	ponyOnTheStack()
{
    Pony pony = Pony();
    std::cout << "You see a cute pony... Give it a name: " ;
    std::cin >> pony.name;
    std::cout << "Your pony " << pony.name << " is sick" << std::endl;
}

int		main()
{
    std::cout << "ponyOnTheHeap: " << std::endl;
    ponyOnTheHeap();
    std::cout << "ponyOnTheStack" << std::endl;
    ponyOnTheStack();
    return(0);
}