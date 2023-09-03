#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <cstdlib>
#include <iomanip>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define NORMAL "\x1b[0m"
#define DELIMITER_HALF "=========="
#define CHAR "char"
#define INT "int"
#define FLOAT "float"
#define DOUBLE "double"
#define NONE "none"

class ScalarConverter
{
private:
    ScalarConverter();

public:
    static void convert(const std::string &str);
    static std::string SetType(const std::string &str);
    // static void printInt(const std::string &str, const std::string &type);
};

#endif