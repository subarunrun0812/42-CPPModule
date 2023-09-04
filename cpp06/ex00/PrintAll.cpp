#include "PrintAll.hpp"

static void printChar(char _c, bool decimal_flag)
{
    if ((0 <= _c && _c < '!') || ('~' < _c && _c <= 127))
    {
        if (decimal_flag == true)
            std::cout << "char: impossible" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else if ('!' <= _c && _c <= '~')
        std::cout << "char: '" << _c << "'" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
}
static void printInt(int _i, bool decimal_flag)
{
    if ((INT_MIN == _i || INT_MAX == _i) && decimal_flag == true)
        std::cout << "int: impossible" << std::endl;
    else if (INT_MIN <= _i && _i <= INT_MAX)
        std::cout << "int: " << _i << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
}
static void printFloat(float _f, int num)
{
    std::cout << "float: ";
    // float型で出力する際、不要な末尾のゼロも表示するようにする
    std::cout << std::fixed << std::setprecision(num) << _f;
    std::cout << "f" << std::endl;
}
static void printDouble(double _d)
{
    std::cout << "double: " << _d << std::endl;
}

void PrintAll(char _c, int _i, float _f, double _d, int num, bool decimal_flag)
{
    std::cout << GREEN;
    printChar(_c, decimal_flag);
    printInt(_i, decimal_flag);
    printFloat(_f, num);
    printDouble(_d);
    std::cout << NORMAL;
}