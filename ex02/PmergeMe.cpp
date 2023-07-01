# include "PmergeMe.hpp"

PMM::PMM():str(){}

PMM::PMM(const std::string& str):str(str){}

PMM::PMM(char** chrarr)
{
	std::string s = " ";
	for (int i = 0; chrarr[i]; ++i)
		str += chrarr[i] + s;
}

PMM::PMM(const PMM &other):str(other.str){}

PMM::~PMM(){}

PMM& PMM::operator=(const PMM &other){
	str = other.str;
	return *this;
}

void merge(vector &nums, int low, int mid, int high) {
	int n1 = mid - low + 1;
	int n2 = high - mid;
	int left[n1], right[n2];
	for (int i = 0; i < n1; i++) {
		left[i] = nums[low + i];
	}
	for (int j = 0; j < n2; j++) {
		right[j] = nums[mid + 1 + j];
	}
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

void merge1(vector &nums, int low, int mid, int high) {
	int n1 = mid - low + 1;
	int n2 = high - mid;
	vector left(nums.begin() + low, nums.begin() + mid + 1);
	vector right(nums.begin() + mid + 1, nums.begin() + high + 1);
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

// void mergesort(vector &nums, int low, int high)
void mergesort(vector &nums, int low, int high, void (*mg)(vector &nums, int low, int mid, int high))
{
	if (low < high) {
		int mid = low + (high - low) / 2;
		mergesort(nums, low, mid, mg);
		mergesort(nums, mid + 1, high, mg);
		mg(nums, low, mid, high);
	}
	return;
}

void PMM::sortVector() const
{
	vector nums;
	std::stringstream ss(str);
	size_t num;
	for(size_t i = 0; str[i]; ++i)
	{
		if (! (isdigit(str[i]) || isspace(str[i])))
			throw(std::invalid_argument("Invalid input"));
	}

	while ( ss >> num)
		nums.push_back(num);
	
	mergesort(nums, 0, nums.size() - 1, merge);
	// for (vector::iterator it = nums.begin(); it != nums.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
}

void PMM::sortVector1() const
{
	vector nums;
	std::stringstream ss(str);
	size_t num;
	for(size_t i = 0; str[i]; ++i)
	{
		if (! (isdigit(str[i]) || isspace(str[i])))
			throw(std::invalid_argument("Invalid input"));
	}

	while ( ss >> num)
		nums.push_back(num);
	
	mergesort(nums, 0, nums.size() - 1, merge1);
	// for (vector::iterator it = nums.begin(); it != nums.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
}

// void PMM::sortVectorPairs() const
// {
// 	std::vector<std::pair<int, int>> pairs;
// 	std::stringstream ss(str);
// 	size_t num;
// 	for(size_t i = 0; str[i]; ++i)
// 	{
// 		if (! (isdigit(str[i]) || isspace(str[i])))
// 			throw(std::invalid_argument("Invalid input"));
// 	}
// 	while ( ss >> num)
// 		pairs.push_back(std::make_pair(num, 0));
	
// 	mergesort(pairs,
	
	
// }
