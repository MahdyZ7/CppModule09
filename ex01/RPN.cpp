#include "RPN.hpp"

RPN::RPN(void): exp("") , result(0){}
RPN::RPN(cosnt std::string& str): exp(str)
{

}
RPN::RPN(const RPN& other): exp(other.str), result(other.result){}

bool valid_input(std::string str)
{
	std::string op = "*/+-";
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (isspace(str[i]))
			continue;
		else if (isdigit(str[i]))
			continue;
		else if (op.find(str[i]) != std::string::npos && i > 0 && isspace(str[i - 1])\
	&& (isspace(str[i + 1]) || str[i + 1] == '\0'))
			continue;
		else
			std::cout << "Error\n";
		return false;
	}
	return true;
}

int operation(int a, int b, std::string str)
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

int main(int argv, char **argc)
{	
	if (argv != 2)
	{
		std::cout << "Wrong numebr of arguments\n";
		return 0;
	}
	if (!valid_input(argc[1]))
		return 0;
	std::stack<int> s;
	std::string word;
         std::stringstream ss(argc[1]);
		 while (ss >> word)
		 {
			int x = 0;
			if (std::stringstream(word) >> x)
				s.push(x);
			else if (word != "")
			{
				if (s.size() < 2)
				{
					std::cout << "Expression is invalid\n";
					return 0;
				}
				int a = s.top();
				s.pop();
				int b = s.top();
				s.pop();
				s.push(operation(a, b, word));
			}
		 }
		if (s.size() != 1)
			std::cout << "Expression in invalid\n";
		else
			std::cout << s.top();
}