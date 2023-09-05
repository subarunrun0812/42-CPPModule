#include "Span.hpp"

void SubjectTest()
{
    std::cout << LINE " SUBJECT TEST " LINE << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << std::endl;
}

void NormalTest_0()
{
    std::cout << LINE " NORMAL TEST 0 " LINE << std::endl;
    try
    {
        Span sp = Span(2);
        sp.addNumber(6);
        sp.addNumber(2);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
}

void OneElementTest()
{
    std::cout << LINE " ONE ELEMENT TEST " LINE << std::endl;
    try
    {
        Span sp = Span(1);
        sp.addNumber(6);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
}
void OverElementTest()
{
    std::cout << LINE " OVER ELEMENT TEST " LINE << std::endl;
    try
    {
        Span sp = Span(1);
        sp.addNumber(6);
        sp.addNumber(2);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
}

int main()
{
    SubjectTest();
    NormalTest_0();
    OneElementTest();
    OverElementTest();
    return (0);
}