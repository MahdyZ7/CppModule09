#include "RPN.hpp"

static bool valid_input(std::string str)
{
	std::string op = "*/+-";
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (isspace(str[i]))
			continue;
		else if (op.find(str[i]) != std::string::npos ||  isdigit(str[i]))
		{
			if (i > 0 && !isspace(str[i - 1]))
				return (false);
			if (! (isspace(str[i + 1]) || str[i + 1] == '\0'))
				return (false);
			continue;
		}
		return false;
	}
	return true;
}


int main(int argv, char **argc)
{	
	try
	{	
		if (argv != 2)
			throw(std::invalid_argument("Error: invalid number of arguments"));
		if (!valid_input(argc[1]))
			throw(std::invalid_argument("Error: invalid input"));
		RPN rpn(argc[1]);
		rpn.postfix();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}