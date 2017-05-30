#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>

void identify_from_pointer( Base * p );
void identify_from_reference( Base & p );
Base * generate(void);

void identify_from_reference( Base & p )
{
    try{
        (void) dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    } catch (std::bad_cast &e)
    {

    }
    try {
        (void) dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
    } catch (std::bad_cast &e) {

    }
    try {
        (void) dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
    }catch (std::bad_cast &e) {

    }
}

void identify_from_pointer( Base * p )
{
    if (dynamic_cast<A *>(p) != NULL) std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL) std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p) != NULL) std::cout << "C" << std::endl;
}

Base * generate(void) {
    Base *base;

    switch (rand() % 3) {
        case 0:
            base = new A();
            break;
        case 1:
            base = new B();
            break;
        case 2:
            base = new C();
            break;
    }
    return base;
}

int main()
{
    srand(time(NULL));
    Base *base = generate();
    identify_from_pointer(base);
    identify_from_reference(*base);
    return (0);
}