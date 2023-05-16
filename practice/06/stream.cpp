#include <fstream>
#include <iostream>

int main()
{
    
    std::ofstream ofs("hello.txt");
    if (!ofs)
    {
        std::cerr << "ファイルオープンに失敗" << std::endl;
        std::exit(1);
    }

    ofs << "Hello World" << std::endl;
}