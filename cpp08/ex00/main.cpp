#include "easyfind.hpp"

void VectorTest()
{
	std::cout << LINE " VECTOR TEST " LINE << std::endl;
	std::vector<int> vec;
	std::vector<int>::iterator ite;

	for (size_t i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	try
	{
		ite = EasyFind(vec, 3);
		std::cout << "iterator = " << *ite << std::endl;
		ite = EasyFind(vec, 99);
		std::cout << "iterator = " << *ite << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}

void ListTest()
{
	std::cout << LINE " LIST TEST " LINE << std::endl;
	std::list<int> lis;
	std::list<int>::iterator ite;

	for (size_t i = 0; i < 10; i++)
	{
		lis.push_back(i);
	}
	lis.push_front(42);
	try
	{
		ite = EasyFind(lis, 3);
		std::cout << "iterator = " << *ite << std::endl;
		ite = EasyFind(lis, 42);
		std::cout << "iterator = " << *ite << std::endl;
		ite = EasyFind(lis, 99);
		std::cout << "iterator = " << *ite << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

}

int main()
{
	VectorTest();
	ListTest();
}