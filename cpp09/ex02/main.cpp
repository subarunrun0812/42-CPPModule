#include "PmergeMe.hpp"

int main(int argc, char const* argv[])
{
	PmergeMe pvec;
	try
	{
		std::clock_t startTime;
		std::clock_t endTime;
		double totalTime;

		std::cout << LINE " Vector Container " LINE << std::endl;
		pvec.AssingToContainer(argc, argv);
		startTime = std::clock();
		pvec.MergeInsertionSort_Vector();
		endTime = std::clock();
		totalTime = static_cast<double>(endTime - startTime); // us（マイクロ秒）単位
		std::cout << "\x1b[45mVector:" << "Time to process a range of " << (argc - 1) << " elements: " << totalTime << " us" NORMAL << std::endl;

		std::cout << LINE " List Container " LINE << std::endl;
		startTime = std::clock();

		endTime = std::clock();
		totalTime = static_cast<double>(endTime - startTime); // us（マイクロ秒）単位
		std::cout << "\x1b[46m  List:" << "Time to process a range of " << (argc - 1) << " elements: " << totalTime << " us" NORMAL << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}