#include "whatever.hpp"

//swap(与えられた2つの引数の値を入れ替える)
//min(2つの引数の値を比較し、小さい値を返す。同じ場合は2番目の数値を返す)
//max(2つの引数の値を比較し、大きい値を返す。同じ場合は2番目の数値を返す)
int main(void)
{
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	return(0);
}