#include "Fixed.hpp"


int main(void) {
	// int tmp_bits = 22;
	// std::cout << "3.19 * (1 << bits) = " << 3.19 * (1 << tmp_bits) << std::endl;
	// std::cout << "roundf(float(3.19 * (1 << bits))) = " << roundf(float(3.19 * (1 << tmp_bits))) << std::endl;
	// std::cout << " = " << roundf(float(3.19 * (1 << tmp_bits))) / (float)(1 << tmp_bits) << std::endl;
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);//コピーコンストラクタ
	a = Fixed(1234.4321f);//コピー代入演算子
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
