#include "iter.hpp"
/*
void NormalTest_1()
{
	std::cout << LINE " INT " LINE << std::endl;
	int arr[] = {1, 2, 3, 4};

	iter(arr, LENGTH, &Output);
}

void NormalTest_2()
{
	std::cout << LINE " FLOAT " LINE << std::endl;
	float arr[] = {1.1f, 2.2f, 3.3f, 4.4f};

	iter(arr, 4, &Output);
}
void NormalTest_3()
{
	std::cout << LINE " CHAR " LINE << std::endl;
	char arr[] = {'A', 'B', 'C', 'D'};

	iter(arr, 4, &Output);
}
void NormalTest_4()
{
	std::cout << LINE " STRING " LINE << std::endl;
	std::string arr[] = {"I", "am", "Sasaki", "Subaru"};

	iter(arr, 4, &Output);
}

int main()
{
	NormalTest_1();
	NormalTest_2();
	NormalTest_3();
	NormalTest_4();
	return (0);
}
*/

// /*
class Awesome
{
public:
	Awesome(void) : _n(42) { return; }
	int get(void) const { return this->_n; }

private:
	int _n;
};

std::ostream &operator<<(std::ostream &o, Awesome const &rhs)
{
	o << rhs.get();
	return o;
}

template <typename T>
void print(T &x)
{
	std::cout << x << std::endl;
	return;
}

int main()
{
	int tab[] = {0, 1, 2, 3, 4};
	Awesome tab2[5];

	iter(tab, 5, print<const int>);
	iter(tab2, 5, print<Awesome>);

	return 0;
}
// */