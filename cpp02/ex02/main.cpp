#include "Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

/*
	// testcase
	std::cout << "~~ test case(0=false,1=true) ~~" << std::endl;
	std::cout << (a > b) << std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << (a >= b) << std::endl;
	std::cout << (a <= b) << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << (a != b) << std::endl;
	std::cout << "~~ 四則演算 ~~" << std::endl;
	Fixed c(2);
	Fixed d(3);
	std::cout << (c + d) << std::endl;
	std::cout << (c - d) << std::endl;
	std::cout << (c * d) << std::endl;
	std::cout << (c / d) << std::endl;
	std::cout << "~~ インクリメント、デクリメント ~~" << std::endl;
	std::cout << (c++) << std::endl;
	std::cout << (c) << std::endl;
	std::cout << (++c) << std::endl;
	std::cout << (d++) << std::endl;
	std::cout << (d) << std::endl;
	std::cout << (++d) << std::endl;
	std::cout << Fixed::max(c, d) << std::endl;
	std::cout << Fixed::min(c, d) << std::endl;
*/
	return 0;
}
