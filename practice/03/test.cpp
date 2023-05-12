#include <iostream>

void func();

void func()
{
    std::cout << "::func()" << std::endl;
}

namespace util {
    void func();

    void func()
    {
        std::cout << "util::func()" << std::endl;
    }
}

int main()
{
    using util::func;

    func();
}