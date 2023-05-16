#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{
    std::ifstream ifs("hello.txt");
    if (!ifs)
    {
        std::cerr << "ファイルオープンに失敗" << std::endl;
        std::exit (1);
    }

    while (!ifs.eof())
    {
        char c;
        ifs.get(c);
        std::cout << c;
    }
    std::cout << std::flush;
}