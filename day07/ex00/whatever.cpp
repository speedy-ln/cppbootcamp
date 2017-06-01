#include <iostream>

template<typename T>
T const & max(T const & v1, T const & v2)
{
    return (v1 > v2 ? v1 : v2);
}

template<typename T>
T const & min(T const & v1, T const & v2)
{
    return (v1<v2 ? v1 : v2);
}

template<typename T>
void swap(T & v1, T & v2)
{
    T tmp = v1;
    v1 = v2;
    v2 = tmp;
}

int main( void ) {


    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

//
//
//    int a = 10;
//    int e = 10;
//    int b = 20;
//    std::string c = "string";
//    std::string d = "STRING";
//
//    std::cout << "int swap demonstration: " << std::endl << "a = " << a << ", b = " << b << std::endl << "swapping a and b" << std::endl;
//    swap( a, b );
//    std::cout << "a = " << a << ", b = " << b << std::endl <<std::endl;
//
//    std::cout << "string swap demonstration: " << std::endl << "c = " << c << ", d = " << d << std::endl << "swapping c and d" << std::endl;
//    swap(c, d);
//    std::cout << "c = " << c << ", d = " << d << std::endl;
//    std::cout << std::endl;
//
//    std::cout << "min & max demonstration: " << std::endl << "min( " << a << ", " << b << " ) = " << ::min( a, b ) << std::endl;
//    std::cout << "max( " << a <<", " << b << " ) = " << ::max( a, b ) << std::endl;
//
//    std::cout << "min( " << c << ", " << d << " ) = " << ::min( c, d ) << std::endl;
//    std::cout << "max( " << c << ", " << d << " ) = " << ::max( c, d ) << std::endl;
//
//    std::cout << std::endl;
//
//    a = 10;
//    e = 10;
//    std::cout << "min & max equal demonstration: "
//              << "a = " << a << ", e = " << e << std::endl << "min(a, e) and max(a, e)"
//              << std::endl << "min( " << a << ", " << e << " ) = " << ::min( a, e ) << std::endl;
//    std::cout << "max( " << a <<", " << e << " ) = " << ::max( a, e ) << std::endl;
//    std::cout << "Address of return value of max: " <<  &::max(a, e) << std::endl;
//    std::cout << "Address of return value of e: " << &e << std::endl;
//    std::cout << "Address of return value of a: " <<  &a << std::endl;
//
//    std::cout << std::endl;
//
//    std::cout << "Address of return value of min: " <<  &::min(a, e) << std::endl;
//    std::cout << "Address of return value of e: " << &e << std::endl;
//    std::cout << "Address of return value of a: " <<  &a << std::endl;


    return 0;
}