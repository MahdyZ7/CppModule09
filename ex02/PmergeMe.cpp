#include "PmergeMe.hpp"



bool is_valid(const std::string& str)
{
	size_t	num = 0;

	for (size_t i = 0; str[i]; ++i)
	{
		if (std::isspace(str[i]))
		{
			num = 0;
			continue ;
		}
		if (!isdigit(str[i]))
			return (false);
		num = num * 10 + (str[i] - '0');
		if (num >> 31)
			return (false);
	}
	return (true);
}
