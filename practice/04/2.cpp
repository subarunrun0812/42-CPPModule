#include <iostream>
#include <sstream>

int main()
{
    std::ostringstream oss;
    oss << "ostringstream sample: " << 123 << 1 << 123 + 1;

    std::string str(oss.str());
    std::cout << str << std::endl;
}