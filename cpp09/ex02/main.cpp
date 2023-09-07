#include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
    PmergeMe pvec;
    try
    {
        pvec.AssingToVector(argc, argv);
        // pvec.AssingToList(argc, argv);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}