#include "PmergeMe.hpp"

int main(int argc, char const* argv[])
{
	PmergeMe pvec;
	try
	{
		// pvec.AssingToList(argc, argv);
		pvec.AssingToVector(argc, argv);
		pvec.MergeInsertionSort_Vector();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}