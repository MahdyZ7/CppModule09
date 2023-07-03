#include "PmergeMe.hpp"



int main(int argc, char** argv) {
	try
	{
		if (argc <  2)
			throw(std::invalid_argument("Error: Invalid number of arguments"));
		{
			clock_t start = clock();
			PMM<pairlist> a(&argv[1]);
			a.sort();
			clock_t end = clock();
			std::cout << "Before\t: " << a.getStr() << std::endl; 
			std::cout << "After\t: "; a.printNums();
			print_time(a.getSize(), "list", start, end);
			
		}
		{
			clock_t start = clock();
			PMM<pairdeque, intdeque> a(&argv[1]);
			a.sort();
			clock_t end = clock();
			print_time(a.getSize(), "deque", start, end);
		}
		// {
		// 	clock_t start = clock();
		// 	PMM<pairvector, intvector> a(&argv[1]);
		// 	a.sort();
		// 	clock_t end = clock();
		// 	print_time(a.getSize(), "vector", start, end);
		// }
		return(0);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
}