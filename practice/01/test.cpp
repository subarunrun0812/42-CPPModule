#include <iostream>
#include <cstring>

int func()
{
    return (1);
}

int main()
{
    if (int a = func())
    {
        std::cout << a << " is true" << std::endl;
    }
    else
    {
        std::cout << a << " is false" << std::endl;
    }
}