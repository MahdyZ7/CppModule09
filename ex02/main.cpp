#include "PmergeMe.hpp"

// template<class T, class F>
// void timing(PMM<T, F>& pmm, void (PMM<T, F>::*sort)(void) const)
// {
// 	clock_t begin = clock();
// 	for (int i = 0; i < 1000; i++)
// 		(pmm.*sort)();
// 	clock_t end = clock();
// 	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
// 	std::cout << "Time spent: " << time_spent << " seconds" << std::endl;
// }

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}
	try
	{
		(void) argv;
		// clock_t start = clock();
		PMM<mylist> a;
		// a.sort();
		// timing(a, &PMM::sortVector);
		// timing(a, &PMM::sortVector1);
		// a.sortVector();
		// a.sortVector1();
		// clock_t end = clock();
  //   	double duration = (end - start) / (double)CLOCKS_PER_SEC;
  //   	std::cout << "Execution time: " << duration << " seconds" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
}