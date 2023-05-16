#include <iostream>
#include <sstream>
#include <string>

namespace{
    void func(const char* s, std::size_t size)
    {
        if (s->empty()){
            std::cout << *s << "empty" << s->size() << std::endl;
        }
    }
}

int main()
{
    char s1[10] = "abced";
    char s2[10] = "";


}