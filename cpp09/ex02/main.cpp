#include "PmergeMe.hpp"

int main(int argc, char const* argv[])
{
	PmergeMe pvec;
	try
	{
		pvec.AssingToContainer(argc, argv);
		
		std::cout << LINE " Vector Container " LINE << std::endl;
		std::clock_t startTimeVec = std::clock();
		pvec.MergeInsertionSort_Vector();
		std::clock_t endTimeVec = std::clock();
		double totalTimeVec = static_cast<double>(endTimeVec - startTimeVec); // us（マイクロ秒）単位

		std::cout << LINE " List Container " LINE << std::endl;
		std::clock_t startTimeList = std::clock();
		pvec.MergeInsertionSort_List();
		std::clock_t endTimeList = std::clock();
		double totalTimeList = static_cast<double>(endTimeList - startTimeList); // us（マイクロ秒）単位

		std::cout << LINE " TIME " LINE << std::endl;
		std::cout << "Vector:" << "Time to process a range of " << (argc - 1)\
		 << " elements: " GREEN << totalTimeVec << " us" NORMAL << std::endl;
		std::cout << "List:" << "Time to process a range of " << (argc - 1)\
		 << " elements: "  GREEN << totalTimeList << " us" NORMAL << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}