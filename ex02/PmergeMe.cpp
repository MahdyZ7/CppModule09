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

void mergelist(list &nums, int low, int mid, int high) {
	int n1 = mid - low + 1;
	int n2 = high - mid;
	std::pair<int,int> left[n1], right[n2];
	list::iterator l_first = nums.begin();
	list::iterator r_first = nums.begin();
	std::advance(l_first, low);
	std::advance(r_first, mid + 1);
	list::iterator pos = l_first;
	for (int i = 0; i < n1; i++) {
		left[i] = *(l_first++);
	}
	for (int j = 0; j < n2; j++) {
		right[j] = *(r_first++);
	}
	int i = 0, j = 0;
	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			*pos = left[i];
			i++;
		} else {
			*pos = right[j];
			j++;
		}
		++pos;
	}
	while (i < n1) {
		*pos = left[i];
		i++;
		++pos;
	}
	while (j < n2) {
		*pos = right[j];
		j++;
		++pos;
	}
}
	
void printpair(list lst)
{
	list::iterator it = lst.begin();
	while (it != lst.end()) {
		std::cout << "[" << it->first << " " 
			<< it->second << "] ";
		++it;
		if (it != lst.end())
			std::cout << "-> ";
		else
			std::cout << std::endl;
	}
}

void printlist(std::list<int> lst)
{
	std::list<int>::iterator it = lst.begin();
	while (it != lst.end()) {
		std::cout << *it << " ";
		++it;
		if (it != lst.end())
			std::cout << "-> ";
		else
			std::cout << std::endl;
	}
}

void mergeSort(list &nums, int low, int high)
{
	if (low < high) {
		int mid = low + (high - low) / 2;
		printpair(nums);
		mergeSort(nums, low, mid);
		mergeSort(nums, mid + 1, high);
		mergelist(nums, low, mid, high);
	}
	return;
}


void PMM::sortListPairs() const
{
	list pairs;
	std::stringstream ss(str);
	size_t num;
	for(size_t i = 0; str[i]; ++i)
	{
		if (! (isdigit(str[i]) || isspace(str[i])))
			throw(std::invalid_argument("Invalid input"));
	}

	std::pair<int, int> temp_pair;
	int i = 0, lone_num = -1;
	for (; ss >> num; ++i)
	{
		if (i % 2 == 0)
			temp_pair.first = num;
		else
		{
			temp_pair.second = num;
			if (temp_pair.first < temp_pair.second)
				std::swap(temp_pair.first, temp_pair.second);
			pairs.push_back(temp_pair);
		}
	}
	if (i % 2 == 1)
		lone_num = temp_pair.first;

	printpair(pairs);
	std::cout << pairs.size() << " " << i/2 << std::endl;
	mergeSort(pairs, 0, pairs.size() - 1);
	printpair(pairs);
	std::cout << "Lone number: " << lone_num << std::endl;


	std::list<int> nums;
	nums.push_back(pairs.begin()->second);
	nums.push_back(pairs.begin()->first);
	list::iterator it = pairs.begin();
	++it;
	for (; it != pairs.end(); ++it)
	{
		nums.push_back(it->first);
		std::cout << "number to be inserted: " << it->second << std::endl;
		std::cout << "lower bound of number: " << *std::lower_bound(nums.begin(), nums.end(), it->second) << std::endl;
		nums.insert(std::lower_bound(nums.begin(), nums.end(), it->second), it->second);
		printlist(nums);
	}
	if (lone_num != -1)
		nums.insert(std::lower_bound(nums.begin(), nums.end(), lone_num), lone_num);
	printlist(nums);
}
