#include <locale.h>
#include <iostream>

int main()
{
    const int num = 100;
    std::cout << std::showbase
        << std::hex << num << "\n"
        << std::noshowbase
        << std::oct << num << "\n"
        << std::dec << num << std::endl;
}