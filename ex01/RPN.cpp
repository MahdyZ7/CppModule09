#include "RPN.hpp"

static int operation(int a, int b, std::string str)
{
	int op = str[0];
	switch (op)
	{
		case '+':
			return (b + a);
		case '-':
			return (b - a);
		case '/':
			return (b / a);
		case '*':
			return (b * a);
	}
	return (0);
}

RPN::RPN(void): exp(""){}
RPN::RPN(const std::string& str): exp(str){}
RPN::RPN(const RPN& other): exp(other.exp){}
RPN::~RPN(){}

RPN &RPN::operator=(const RPN& other)
{
	exp = other.exp;
	return (*this);
}

void RPN::postfix()
{
	std::stack<int> stk;
	std::string word;
    std::stringstream strstream(this->exp);
	int x;

	while (strstream >> word)
	{
		if (std::stringstream(word) >> x)
			stk.push(x);
		else if (word != "")
		{
			if (stk.size() < 2)
			{
				std::cout << "Expression is invalid\n";
				return ;
			}
			int a = stk.top();
			stk.pop();
			int b = stk.top();
			stk.pop();
			stk.push(operation(a, b, word));
		}
	}
	if (stk.size() != 1)
		std::cout << "Expression in invalid\n";
	else
		std::cout << stk.top() << std::endl;
}
