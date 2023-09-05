#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
#ifdef DEBUG
    std::cout << "Default Constructor called" << std::endl;
#endif
}
template <typename T>
MutantStack<T>::~MutantStack()
{
#ifdef DEBUG
    std::cout << "Destructor called" << std::endl;
#endif
}
template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &mutant)
{
#ifdef DEBUG
    std::cout << "Copy constructor called" << std::endl;
#endif
    (void)mutant;
}
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &mutant)
{
#ifdef DEBUG
    std::cout << "Copy operator called" << std::endl;
#endif
    (void)mutant;
    return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

template <typename T>
void MutantStack<T>::ShowStack(MutantStack<T> &mstack)
{
    std::cout << "    SHOW STACK" << std::endl;
    MutantStack<T>::iterator it = mstack.begin();
    MutantStack<T>::iterator ite = mstack.end();
    // こちらのループを使用して、スタックの内容を逆順に表示します
    while (ite != it)
    {
        --ite;
        std::cout << "|\t" GREEN << *ite << NORMAL "\t|" << std::endl;
    }
    std::cout << std::endl;
}
