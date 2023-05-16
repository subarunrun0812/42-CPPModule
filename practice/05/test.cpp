#include <iostream>

int main()
{
    char str[80];
    int n;
    double d;

    std::cout << "str > ";
    std::cin >> str;
    std::cout << "n > ";
    std::cin >> n;
    std::cout << "d > ";
    std::cin >> d;

    std::cout << str << "\n"
            << n << "\n"
            << d << std::endl;
}