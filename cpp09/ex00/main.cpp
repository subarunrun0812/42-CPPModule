#include "BitcoinExchange.hpp"

int main(int argc, char const* argv[])
{
	if (argc < 2)
	{
		std::cout << RED "Error: could not open file." NORMAL << std::endl;
	}
	else if (argc == 2)
	{
		BX bx;
		bx.Currency(argv[1]);
	}
	else
	{
		std::cout << RED "Error: too many arguments." NORMAL << std::endl;
	}
	return 0;
}
