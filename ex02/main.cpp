#include "PmergeMe.hpp"

void print_time(size_t size, std::string contype, clock_t start, clock_t end)
{
	double duration = (end - start) / (double)CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of " << std::setw(5) << size;
	std::cout <<  " elements with std::" << contype << " : ";
	std::cout << std::fixed << std::setprecision(3)<< duration << " ms" << std::endl;
}

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}
	try
	{
		size_t size = argc - 1;
		{
			clock_t start = clock();
			PMM<pairlist> a(&argv[1]);
			a.sort();
			clock_t end = clock();
			std::cout << "Before\t: " << a.getStr() << std::endl; 
			std::cout << "After\t: "; a.printNums();
			print_time(size, "list", start, end);
			
		}
		{
			clock_t start = clock();
			PMM<pairdeque, intdeque> a(&argv[1]);
			a.sort();
			clock_t end = clock();
			print_time(size, "deque", start, end);
		}
		// {
		// 	clock_t start = clock();
		// 	PMM<pairvector, intvector> a(&argv[1]);
		// 	a.sort();
		// 	clock_t end = clock();
		// 	print_time(size, "vector", start, end);
		// }
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
}