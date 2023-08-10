#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream>
#include <string>

// class file
// {
//     public:
//         std::string strReplace(std::string line, std::string s1, std::string s2);
//     private:
// }

int EditFile(char **argv);
std::string strReplace(std::string line, std::string s1, std::string s2);

#endif