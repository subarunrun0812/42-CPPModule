#include "Array.hpp"

void NormalTest_1()
{
	std::cout << LINE " デフォルトコンストラクタ " LINE << std::endl;
	Array<int> arr1;
	std::cout << "size: " << arr1.size() << std::endl;

	std::cout << LINE " 引数付きコンストラクタ " LINE << std::endl;
	Array<int> arr2(5);
	std::cout << "size: " << arr2.size() << std::endl;
	for (unsigned int i = 0; i < arr2.size(); i++)
	{
		arr2[i] = i;
		std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
	}

	std::cout << LINE " コピーコンストラクタ " LINE << std::endl;
	Array<int> arr3(arr2);
	std::cout << "size: " << arr3.size() << std::endl;
	for (unsigned int i = 0; i < arr3.size(); i++)
	{
		std::cout << "arr3[" << i << "] = " << arr3[i] << std::endl;
	}

	std::cout << LINE " コピー代入演算子 " LINE << std::endl;
	Array<int> arr4;
	arr4 = arr2;
	std::cout << "size: " << arr4.size() << std::endl;
	for (unsigned int i = 0; i < arr4.size(); i++)
	{
		std::cout << "arr4[" << i << "] = " << arr4[i] << std::endl;
	}

	std::cout << LINE " 範囲外へのアクセス " LINE << std::endl;
	try
	{
		std::cout << arr2[10] << std::endl; // これは例外を投げるべきです。
	}
	catch (const std::exception &e)
	{
		std::cerr << RED "エラーの原因: " NORMAL << e.what() << std::endl;
	}
}

int main()
{
	NormalTest_1();

	return (0);
}

#ifdef DEBUG
#include <stdlib.h>
__attribute__((destructor)) static void destructor(void)
{
	system("leaks -q ex02");
}
#endif