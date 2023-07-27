#include <iostream>
#include <fstream>
#include <string>
#include "Harl.hpp"

int main(int argc, char** argv) {
	Harl harl;

	if (argc != 2) {
		std::cout << "missing argument\n";
		return 1;
	}


	if (strcmp(argv[1],"DEBUG") == 0)
		harl.complain("DEBUG");
	else if (strcmp(argv[1], "INFO") == 0)
		harl.complain("INFO");
	else if(strcmp(argv[1],"WARNING") == 0)
		harl.complain("WARNING");
	else if(strcmp(argv[1],"ERROR") == 0)
		harl.complain("ERROR");
	else {
		std::cout << "Invalid log level. Available levels are: DEBUG, INFO, WARNING, ERROR\n";
		return 1;
	}
}
