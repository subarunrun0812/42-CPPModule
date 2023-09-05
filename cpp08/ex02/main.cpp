#include "MutantStack.hpp"

void SubjectTest_1()
{
	std::cout << LINE " SUBJECT TEST 1" LINE << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl;
}

void SubjectTest_2()
{
	std::cout << LINE " SUBJECT TEST 2" LINE << std::endl;
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);
	std::list<int>::iterator it = mlist.begin();
	std::list<int>::iterator ite = mlist.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
}

void NormalTest_1()
{
	std::cout << LINE " NORMAL TEST 1" LINE << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.ShowStack(mstack);
	std::cout << "スタックをPOPする" << std::endl;
	mstack.pop();

	mstack.push(3);
	mstack.push(8);
	mstack.push(737);
	mstack.push(0);
	mstack.ShowStack(mstack);
	std::stack<int> s(mstack);
	std::cout << std::endl;
}
void NormalTest_2()
{
	std::cout << LINE " NORMAL TEST 2" LINE << std::endl;
	MutantStack<std::string> mstack;
	mstack.push("🐶");
	mstack.push("🐺	");
	mstack.ShowStack(mstack);
	std::cout << "スタックをPOPする" << std::endl;
	mstack.pop();
	std::cout << "スタックをPOPする" << std::endl;
	mstack.pop();
	mstack.ShowStack(mstack);

	mstack.push("🐱");
	mstack.push("🐭");
	mstack.push("🐹");
	std::cout << "スタックをPOPする" << std::endl;
	mstack.pop();
	mstack.ShowStack(mstack);
	mstack.push("🐰");
	mstack.ShowStack(mstack);
	std::stack<std::string> s(mstack);
	std::cout << std::endl;
}

int main()
{
	SubjectTest_1();
	SubjectTest_2();
	NormalTest_1();
	NormalTest_2();
	return 0;
}