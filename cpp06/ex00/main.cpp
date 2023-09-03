#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << RED "error: argument missing" NORMAL << std::endl;
    }
    else if (argc == 2)
    {
        ScalarConverter::convert(argv[1]);
    }
    else
    {
        std::cout << RED "error: too many argument" NORMAL << std::endl;
    }
    return (0);
}
