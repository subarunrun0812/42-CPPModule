#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	//参照
	std::string& stringREF = str;;

	std::cout << "=== address ===" << std::endl;
	std::cout << "      str=" << &str << std::endl;
	std::cout << "stringPTR=" << stringPTR << std::endl;
	std::cout << "stringREF=" << &stringREF << std::endl;

	std::cout << "=== value ===" << std::endl;
	std::cout << "      str=" << str << std::endl;
	std::cout << "stringPTR=" << *stringPTR << std::endl;
	std::cout << "stringREF=" << stringREF << std::endl;
}
