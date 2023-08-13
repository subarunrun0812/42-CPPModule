#include "file.hpp"

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "Missing argument" << std::endl;
		return (1);
	}

	return (EditFile(argv));
}