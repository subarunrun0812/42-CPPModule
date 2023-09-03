#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
#ifdef DEBUG
    std::cout << "AForm\tdefault constructor called" << std::endl;
#endif
}

bool CheckIntenger(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (('0' <= str[i] && str[i] <= '9') || (str[i] == '+' || str[i] == '-'))
            continue;
        else
            return (false);
    }
    return (true);
}

bool CheckDecimalPoint(const std::string &str)
{
    int num = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (('0' <= str[i] && str[i] <= '9') || (str[i] == '+' || str[i] == '-'))
            ;
        else if (str[i] == '.')
        {
            num++;
            if (num > 1)
                return (false);
            else if (0 == i || i >= str.length() - 1)
                return (false);
            else if (i >= str.length() - 2 && str[str.length() - 1] == 'f')
                return (false);
        }
        else if (i == str.length() - 1 && str[i] == 'f')
        {
            return (true);
        }
        else
            return (false);
    }
    return (true);
}

std::string ScalarConverter::SetType(const std::string &str)
{
    if (str.length() == 1 && !CheckIntenger(str))
        return CHAR;
    else if (str == "nanf" || str == "+inff" || str == "-inff")
        return FLOAT;
    else if (str == "nan" || str == "+inf" || str == "-inf")
        return DOUBLE;
    else if (CheckIntenger(str))
        return INT;
    else if (CheckDecimalPoint(str) && str[str.length() - 1] == 'f')
        return FLOAT;
    else if (CheckDecimalPoint(str))
        return DOUBLE;
    else
        return NONE;
}

void printChar(char _c)
{
    if ('!' <= _c && _c <= '~')
        std::cout << "char: " << _c << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}
void printInt(int _i)
{
    if (INT_MIN <= _i && _i <= INT_MAX)
        std::cout << "int: " << _i << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
}
void printFloat(float _f, int num)
{
    std::cout << "float: ";
    // float型で出力する際、不要な末尾のゼロも表示するようにする
    std::cout << std::fixed << std::setprecision(num) << _f;
    std::cout << "f" << std::endl;
}
void printDouble(double _d)
{
    std::cout << "double: " << _d << std::endl;
}

void PrintAll(char _c, int _i, float _f, double _d, int num)
{
    std::cout << GREEN;
    printChar(_c);
    printInt(_i);
    printFloat(_f, num);
    printDouble(_d);
    std::cout << NORMAL;
}
void ScalarConverter::convert(const std::string &str)
{
    // 受け取った文字列が何の型か判断する
    std::string type = SetType(str);
    if (type == NONE)
    {
        std::cout << RED "どの型にも一致しません" NORMAL << std::endl;
        return;
    }
#ifdef DEBUG
    std::cout << "type = " << type << std::endl;
#endif
    if (type == CHAR)
    {
        char _c = str[0];
        int _i = static_cast<int>(_c);
        float _f = static_cast<float>(_c);
        double _d = static_cast<double>(_c);
        PrintAll(_c, _i, _f, _d, 1);
    }
    else if (type == INT)
    {
        int _i = std::stoi(str);
        char _c = static_cast<char>(_i);
        float _f = static_cast<float>(_i);
        double _d = static_cast<double>(_i);
        PrintAll(_c, _i, _f, _d, 1);
    }
    else if (type == FLOAT || type == DOUBLE)
    {
        // 小数点以下の文字列を数える
        int num = 1;
        bool flag = false;
        for (size_t i = 0; i < str.length(); i++)
        {
            if ('0' <= str[i] && str[i] <= '9' && flag == true)
            {
                num++;
            }
            if (str[i] == '.')
            {
                num = 0;
                flag = true;
            }
        }
        std::cout << "num = " << num << std::endl;
        if (type == FLOAT)
        {
            float _f = std::stof(str);
            char _c = static_cast<char>(_f);
            int _i = static_cast<int>(_f);
            double _d = static_cast<double>(_f);
            PrintAll(_c, _i, _f, _d, num);
        }
        else if (type == DOUBLE)
        {
            double _d = std::stod(str);
            char _c = static_cast<char>(_d);
            int _i = static_cast<int>(_d);
            float _f = static_cast<float>(_d);
            PrintAll(_c, _i, _f, _d, num);
        }
    }
    // // char
    // if (str.length() == 1)
    // {
    //     char charValue = str[0];
    //     if (' ' <= charValue && charValue <= '~')
    //         std::cout << "char: " << charValue << std::endl;
    //     else
    //         std::cout << "char: Non displayable" << std::endl;
    // }
    // else
    //     std::cout << "char: impossible" << std::endl;

    // int

    // float

    // double
}