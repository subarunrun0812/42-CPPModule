#include <iostream>
#include <fstream>
#include <string>
#include "Harl.hpp"

int main() {
    Harl harl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    harl.complain("aaa");
    harl.complain("");

    return 0;
}
