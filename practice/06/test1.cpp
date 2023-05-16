#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>

int main(void)
{
    std::cout << "文字列を入力してください" << std::endl;
    std::string str;
    std::cin >> str;

    std::ofstream ofs("test1.txt");
    ofs << str << std::endl;

}