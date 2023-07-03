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

void print_time(size_t size, std::string contype, clock_t start, clock_t end)
{
	double duration = (end - start) / (double)CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of " << std::setw(5) << size;
	std::cout <<  " elements with std::" << contype << " : ";
	std::cout << std::fixed << std::setprecision(3)<< duration << " ms" << std::endl;
}
