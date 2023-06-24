#include "RPN.hpp"

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


int main(int argv, char **argc)
{	
	if (argv != 2)
	{
		std::cout << "Wrong numebr of arguments\n";
		return 0;
	}
	if (!valid_input(argc[1]))
		return 0;
	RPN a(argc[1]);
	a.postfix();
}