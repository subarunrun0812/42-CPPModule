#include <iostream>
#include <fstream>
#include <string>
#include "Harl.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "missing argument\n";
		return 1;
	}

	selectionComplain(argv[1]);
}
