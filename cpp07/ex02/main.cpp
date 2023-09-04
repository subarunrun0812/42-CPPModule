#include "iter.hpp"

void NormalTest_1()
{
	std::cout << LINE " INT " LINE << std::endl;
	int arr[] = {1, 2, 3, 4};

	iter(arr, LENGTH, &print);
}

void NormalTest_2()
{
	std::cout << LINE " FLOAT " LINE << std::endl;
	float arr[] = {1.1f, 2.2f, 3.3f, 4.4f};

	iter(arr, 4, &print);
}
void NormalTest_3()
{
	std::cout << LINE " CHAR " LINE << std::endl;
	char arr[] = {'A', 'B', 'C', 'D'};

	iter(arr, 4, &print);
}
void NormalTest_4()
{
	std::cout << LINE " STRING " LINE << std::endl;
	std::string arr[] = {"I", "am", "Sasaki", "Subaru"};

	iter(arr, 4, &print);
}

int main()
{
	NormalTest_1();
	NormalTest_2();
	NormalTest_3();
	NormalTest_4();
	return (0);
}