#include <string>
#include <iostream>

int main()
{
    std::string str("abcde");
    std::cout << str[2] << std::endl;

    str[2] = 'x';
    std::cout << str[2] << std::endl;

    char *p = &str[2];
    *p = '?';
    std::cout << str[2] << std::endl;
}