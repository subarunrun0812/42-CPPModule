#include <string>
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream ifs("hello.txt");
    if (!ifs)
    {
        std::cerr << "ファイルオープンに失敗" << std::endl;
        std::exit(1);
    }

    while (!ifs.eof())
    {
        std::string buf;
        std::getline(ifs,buf);
        std::cout << buf << std::endl;
    }

}