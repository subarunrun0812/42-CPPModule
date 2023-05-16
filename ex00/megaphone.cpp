// 小文字を大文字に変換する
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    int i = 1;
    while (i < argc)
    {
        if (i != 1)
        {
            std::cout << ' ';
        }
        std::string str = argv[i];

        transform (str.begin(), str.end() , str.begin() , toupper);
        std::cout << str;
        i++;
    }
    std::cout << std::endl;
    return (0);
}
