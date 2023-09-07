#include "RPN.hpp"

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

	while (std::getline(ss, token, ' '))
	{
		if (token.empty())
			continue;
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
			st.push(Calculation(token[0], num1, num2));
		}
		else
		{
			if (std::stoi(token) < 0 || 10 < std::stoi(token))
				throw ErrorNumber();
			st.push(std::stoi(token));
		}

	}

	if (st.size() != 1)
	{
		throw ErrorResult();
	}
	return st.top();
}
