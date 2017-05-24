#include "Pony.hpp"

void	ponyOnTheHeap()
{
    Pony*   pony = new Pony();
    std::string str;
    std::cout << "You see a cute pony... Give it a name: " ;
    std::cin >> str;
    pony->setName(str);
    std::cout << "Your pony " << pony->getName() << " is sick" << std::endl;
    delete pony;
    std::cout << std::endl;
}

void	ponyOnTheStack()
{
    Pony pony = Pony();
    std::string str;
    std::cout << "You see a cute pony... Give it a name: " ;
    std::cin >> str;
    pony.setName(str);
    std::cout << "Your pony " << pony.getName() << " is sick" << std::endl;
}

int		main()
{
    std::cout << "ponyOnTheHeap: " << std::endl;
    ponyOnTheHeap();
    std::cout << "ponyOnTheStack" << std::endl;
    ponyOnTheStack();
    return(0);
}