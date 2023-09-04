#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base *generate(void)
{
	// TODO:ランダムにA,B,Cクラスをインスタンス化する
	//  シードの設定
	srand(static_cast<unsigned int>(time(0)));

	int random_num = rand() % 3;
#ifdef DEBUG
	std::cout << "rand() = " << rand() << std::endl;
	std::cout << "random_num = " << random_num << std::endl;
#endif
	if (random_num == 0)
	{
		std::cout << GREEN "Aオブジェクトが作成された" NORMAL << std::endl;
		return (new A);
	}
	else if (random_num == 1)
	{
		std::cout << GREEN "Bオブジェクトが作成された" NORMAL << std::endl;
		return (new B);
	}
	else if (random_num == 2)
	{
		std::cout << GREEN "Cオブジェクトが作成された" NORMAL << std::endl;
		return (new C);
	}
	return NULL;
}

void identify(Base *p)
{
	std::cout << LINE " ポインタ型 " LINE << std::endl;
	if (dynamic_cast<A *>(p))
		std::cout << GREEN "これはAオブジェクトです!!" NORMAL << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << GREEN "これはBオブジェクトです!!" NORMAL << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << GREEN "これはCオブジェクトです!!" NORMAL << std::endl;
}

void identify(Base &p)
{
	std::cout << LINE " 参照型 " LINE << std::endl;
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << GREEN "これはAオブジェクトです!!" NORMAL << std::endl;
	}
	catch (const std::bad_cast &e)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << GREEN "これはBオブジェクトです!!" NORMAL << std::endl;
	}
	catch (const std::bad_cast &e)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << GREEN "これはCオブジェクトです!!" NORMAL << std::endl;
	}
	catch (const std::bad_cast &e)
	{
	}
}

int main(void)
{
	Base *base = generate();
	identify(base);
	identify(*base);
}