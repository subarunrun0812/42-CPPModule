#include <iostream>

void twice( int& a )
{
    std::cout << a << std::endl;
    a *= 2;
    std::cout << a << std::endl;
}
int main()
{
    int v = 16;
    std::cout << v << std::endl;
    twice( v );
    std::cout << v << std::endl;
}

