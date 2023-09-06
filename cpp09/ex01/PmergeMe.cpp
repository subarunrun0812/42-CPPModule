#include "PmergeMe.hpp"

bool isOperator(const char& token)
{
	return (token == '+' || token == '-' \
		|| token == '*' || token == '/');
}

int Calculation(const char& operation, int num1, int num2)
{
	switch (operation)
	{
	case '+':
		return (num1 + num2);
	case '-':
		return (num1 - num2);
	case '*':
		return (num1 * num2);
	case '/':
		return (num1 / num2);
	default:
		throw ErrorOperator();
	}
}

int ReversePolishNotation(std::string line)
{
	std::stack<int> st;
	std::stringstream ss(line);
	std::string token;

	while (ss >> token)
	{
		//オペレーターの場合
		if (isOperator(token[0]))
		{
			if (st.size() < 2)
			{
				throw ErrorTokenize();
			}
			//上から取り出す
			int num2 = st.top();
			st.pop();
			int num1 = st.top();
			st.pop();
			// std::cout << "num1 = " << num1 << std::endl;
			// std::cout << "token[0] = " << token[0] << std::endl;
			// std::cout << "num2 = " << num2 << std::endl;
			// std::cout << GREEN "現在の数値は" << \
				// Calculation(token[0], num1, num2) << NORMAL << std::endl;
			st.push(Calculation(token[0], num1, num2));
		}
		else
		{
			if (std::stoi(token) < 0 || 10 < std::stoi(token))
				throw ErrorTokenize();
			st.push(std::stoi(token));
		}

	}

	if (st.size() != 1)
	{
		throw ErrorResult();
	}
	return st.top();
}

int main(int argc, char const* argv[])
{
	if (argc < 2)
	{
		std::cout << RED "Error: missing arguments" NORMAL << std::endl;
		return (FAILE);
	}

	try
	{
		int res = ReversePolishNotation(argv[1]);
		std::cout << res << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


}
