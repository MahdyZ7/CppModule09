#include "PmergeMe.hpp"

void insertSort(std::vector<int> &nums, int start, int end) {
	for (int i = start + 1; i < end; ++i) {
		int key = nums[i];
		int j = i - 1;
		while (j >= 0 && nums[j] > key) {
			nums[j + 1] = nums[j];
			j = j - 1;
		}
		nums[j + 1] = key;
	}
}

void merge(std::vector<int> &nums, int low, int mid, int high) {
	int n1 = mid - low + 1;
	int n2 = high - mid;

	std::vector<int> left(n1);
	std::vector<int> right(n2);

	for (int i = 0; i < n1; i++)
		left[i] = nums[low + i];
	for (int j = 0; j < n2; j++)
		right[j] = nums[mid + 1 + j];
	int i = 0, j = 0, k = low;
	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			nums[k] = left[i];
			i++;
		} else {
			nums[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		nums[k] = left[i];
		i++;
		k++;
	}

	while (j < n2) {
		nums[k] = right[j];
		j++;
		k++;
	}
}

void mergeSort(std::vector<int> &nums, int low, int high) {
	if (low < high) {
		int mid = low + (high - low) / 2;
		mergeSort(nums, low, mid);
		mergeSort(nums, mid + 1, high);

		merge(nums, low, mid, high);
		// insertSort(nums, low, high);
	}
}

void timing(PMM& pmm, void (PMM::*sort)(void) const)
{
	clock_t begin = clock();
	for (int i = 0; i < 1000; i++)
		(pmm.*sort)();
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	std::cout << "Time spent: " << time_spent << " seconds" << std::endl;
}

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}
	try
	{
		
		// clock_t start = clock();
		PMM a(&argv[1]);
		timing(a, &PMM::sortVector);
		timing(a, &PMM::sortVector1);
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
// int main() {
// 	int input[] = {9, 5, 2, 7, 1, 8, 3, 6, 4};
// 	std::vector<int> nums;
// 	for (int i = 0; i < 9; i++) {
// 		nums.push_back(input[i]);
// 		std::cout << nums[i] << " ";
// 	}
// 	std::cout << "\n";

// 	mergeSort(nums, 0, nums.size() - 1);

// 	std::cout << "Sorted array: ";
// 	for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;

// 	return 0;
// }
	
// int main() {
//	 int input[] = {9, 5, 2, 7, 1, 8, 3, 6, 4};
//	 std::vector<int> nums;
//	 for (int i = 0; i < 9; i++) {
//		 nums.push_back(input[i]);
//		 std::cout << nums[i] << " ";
//	 }
//	 std::cout << "\n";
//	 insertSort(nums, 0, nums.size());

//	 std::cout << "Sorted array: ";
//	 for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
//	 {
//		 std::cout << *it << " ";
//	 }
//	 std::cout << std::endl;

//	 return 0;
// }
