#include <iostream>

int main()
{
    //cerrはバッファリングされない
    std::cerr << "cerr" << std::endl;
    //cerrはバッファリングされる
    std::clog << "clog" << std::endl;
}