#include "RPN.hpp"

int main(int argc, char const* argv[])
{
	if (argc < 2)
	{
		std::cout << RED "Error: missing arguments" NORMAL << std::endl;
		return (FAILE);
	}

	try
	{
		int res = ReversePolishNotation(argv[1]);
		std::cout << res << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


}