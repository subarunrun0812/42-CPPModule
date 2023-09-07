#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}
PmergeMe::~PmergeMe()
{
}
PmergeMe::PmergeMe(const PmergeMe &pmergeme)
{
    (void)pmergeme;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &pmergeme)
{
    (void)pmergeme;
    return (*this);
}

void PmergeMe::AssingToVector(int argc, const char **argv)
{
    long num;
    for (int i = 1; i < argc; i++)
    {
        num = std::stoi(argv[i]);
        if (num < 0 || INT_MAX < num)
            throw ErrorParametor();
        this->_vec.push_back(static_cast<int>(num));
    }

#if DEBUG
    std::cout << LINE "AssingToVector" LINE << std::endl;
    std::vector<int>::iterator ite;
    for (std::vector<int>::iterator ite = _vec.begin(); ite < _vec.end(); *ite++)
    {
        std::cout << "*ite = " << *ite << std::endl;
    }
    std::cout << std::endl;
#endif
}

void PmergeMe::AssingToList(int argc, const char **argv)
{
    long num;
    for (int i = 1; i < argc; i++)
    {
        num = std::stoi(argv[i]);
        if (num < 0 || INT_MAX < num)
            throw ErrorParametor();
        this->_list.push_back(static_cast<int>(num));
    }

#if DEBUG
    std::cout << LINE "AssingToList" LINE << std::endl;
    std::list<int>::iterator ite;
    for (std::list<int>::iterator ite = _list.begin(); ite != _list.end(); *ite++)
    {
        std::cout << "*ite = " << *ite << std::endl;
    }
    std::cout << std::endl;
#endif
}