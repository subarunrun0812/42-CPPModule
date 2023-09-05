#ifndef MUTANTSTACK
#define MUTANTSTACK

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define NORMAL "\x1b[0m"
#define LINE "=========="
#define LENGTH 4

#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
public:
    MutantStack();
    ~MutantStack();
    MutantStack(const MutantStack<T> &mutant);
    MutantStack<T> &operator=(const MutantStack<T> &mutant);

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin();
    iterator end();
    void ShowStack(MutantStack<T> &mutant);
};

#include "MutantStack.tpp"

#endif