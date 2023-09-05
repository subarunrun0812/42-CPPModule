#ifndef SPAN_HPP
#define SPAN_HPP

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define NORMAL "\x1b[0m"
#define LINE "=========="
#define LENGTH 4

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

class Span
{
private:
    std::vector<int> _vec;
    unsigned int _size;

public:
    Span();
    Span(unsigned int num);
    ~Span();
    Span(const Span &span);
    Span &operator=(const Span &span);
    void addNumber(const int num);
    int shortestSpan();
    int longestSpan();
    int SmallestNumber();
    int LargestNumber();

    //========== 例外クラス ==========
    class NotEnoughElement : public std::exception
    {
        const char *what() const throw()
        {
            return (RED "要素数が1個以下の為、探索出来ません💢💢" NORMAL);
        }
    };
    class TooManyElements : public std::exception
    {
        const char *what() const throw()
        {
            return (RED "これ以上要素を追加出来ません😡😡" NORMAL);
        }
    };
};

#endif