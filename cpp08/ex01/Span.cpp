#include "Span.hpp"

Span::Span()
{
#ifdef DEBUG
    std::cout << "Default Constructor called" << std::endl;
#endif
}

Span::Span(unsigned int num)
{
#ifdef DEBUG
    std::cout << "Constructor called" << std::endl;
#endif
    this->_size = num;
}

Span::~Span()
{
#ifdef DEBUG
    std::cout << "Destructor called" << std::endl;
#endif
}

Span::Span(const Span &span)
{
#ifdef DEBUG
    std::cout << "Copy Constructor called" << std::endl;
#endif
    this->_vec = span._vec;
    this->_size = span._size;
}

Span &Span::operator=(const Span &span)
{
#ifdef DEBUG
    std::cout << "Copy Operator called" << std::endl;
#endif
    this->_vec = span._vec;
    this->_size = span._size;
    return (*this);
}
void Span::addNumber(int num)
{
    // vec.size() = 格納されている要素数
    if (_vec.size() < _size)
    {
        _vec.push_back(num);
    }
    else
    {
        throw NotEnoughElement();
    }
}
int Span::shortestSpan()
{
    if (_vec.size() <= 1)
        throw NotEnoughElement();
    int res = longestSpan();

    for (std::vector<int>::iterator i = _vec.begin(); i < _vec.end() - 1; i++)
    {
        int num_1 = *i;
        int num_2 = *(i + 1);
        if (num_1 > num_2)
        {
            if (res > num_1 - num_2)
                res = num_1 - num_2;
        }
        else
        {
            if (res > num_2 - num_1)
                res = num_2 - num_1;
        }
    }
    return (res);
}

int Span::longestSpan()
{
    if (_vec.size() <= 1)
        throw NotEnoughElement();
    return (LargestNumber() - SmallestNumber());
}

int Span::SmallestNumber()
{
    int res = *(_vec.begin());
    for (std::vector<int>::iterator i = _vec.begin(); i < _vec.end(); i++)
    {
        if (*i < res)
        {
            res = *i;
        }
    }
#ifdef DEBUG
    std::cout << "SmallestNumber = " << res << std::endl;
#endif
    return res;
}
int Span::LargestNumber()
{
    int res = *(_vec.begin());
    for (std::vector<int>::iterator i = _vec.begin(); i < _vec.end(); i++)
    {
        if (*i > res)
        {
            res = *i;
        }
    }
#ifdef DEBUG
    std::cout << "LargestNumber = " << res << std::endl;
#endif
    return res;
}