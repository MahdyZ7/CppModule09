#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
#include <sstream>

typedef std::vector<size_t> vector;
typedef std::list<std::pair<int,int> >		pairlist;
typedef std::list<int>						intlist;
typedef std::deque<std::pair<int,int> >		pairdeque;
typedef std::deque<int>						intdeque;
typedef std::vector<std::pair<int,int> >	pairvector;
typedef std::vector<int>					intvector;


bool is_valid(const std::string& str);
void print_time(size_t size, std::string contype, clock_t start, clock_t end);

template <typename T> void	merge(T &nums, int low, int mid, int high);
template <typename T> void	mergesort(T &nums, int low, int high);
template <class T> void		printnums(T lst);

template <class T = pairlist, class  F = intlist >
class PMM
{
	public:
		PMM();
		PMM(const std::string& str);
		PMM(char** chrarr);
		PMM(const PMM& other);
		~PMM();

		PMM&		operator=(const PMM& other);
		void		sort();
		void		printNums() const;
		std::string getStr() const;
		size_t		getSize() const;
	
	private:
		std::string	str;
		F			nums;
};

template <class T, class  F>
PMM<T,F>::PMM():str(), nums(){}

template <class T, class  F>
PMM<T, F>::PMM(const std::string& str):str(str){
	if (!is_valid(str))
		throw(std::invalid_argument("Error: Invalid input"));
}

template <class T, class  F>
PMM<T, F>::PMM(char** chrarr)
{
	std::string s = " ";
	for (int i = 0; chrarr[i]; ++i)
		str += chrarr[i] + s;
	if (!is_valid(str))
		throw(std::invalid_argument("Error: Invalid input"));
}

template <class T, class  F>
PMM<T, F>::PMM(const PMM &other):str(other.str){}

template <class T, class  F>
PMM<T, F>::~PMM(){}

template <class T, class  F>
PMM<T, F>& PMM<T, F>::operator=(const PMM &other){
	str = other.str;
	nums = other.nums;
	return *this;
}

template <class T, class F>
void PMM<T, F>::sort()
{
	T 					pairs;
	size_t				num, count = 0;
	std::stringstream	ss(str);
	std::pair<int, int>	temp_pair;	

	for (; ss >> num; ++count)
	{
		if (count % 2 == 0)
			temp_pair.first = num;
		else
		{
			temp_pair.second = num;
			if (temp_pair.first < temp_pair.second)
				std::swap(temp_pair.first, temp_pair.second);
			pairs.push_back(temp_pair);
		}
	}
	mergesort(pairs, 0, pairs.size() - 1);
	for(typename T::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		nums.push_back(it->first);
		nums.insert(std::lower_bound(nums.begin(), --nums.end(), it->second), it->second);
	}
	if (count % 2 == 1)
		nums.insert(std::lower_bound(nums.begin(), nums.end(),  temp_pair.first),  temp_pair.first);
}

template <class T, class F>
void PMM<T, F>::printNums() const
{
	typename F::const_iterator it = nums.begin();
	while (it != nums.end()) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

template <class T, class F>
std::string PMM<T, F>::getStr() const
{
	return str;
}

template <class T, class F>
size_t PMM<T, F>::getSize() const
{
	return nums.size();
}

template <typename T>
void merge(T &nums, int low, int mid, int high)
{
	int n1 = mid - low + 1;
	int n2 = high - mid;
	std::pair<int,int> left[n1], right[n2];
	typename T::iterator l_first = nums.begin(), r_first = nums.begin();
	std::advance(l_first, low);
	std::advance(r_first, mid + 1);
	typename T::iterator pos = l_first;

	for (int i = 0; i < n1; i++)
		left[i] = *(l_first++);
	for (int j = 0; j < n2; j++)
		right[j] = *(r_first++);
	int i = 0, j = 0;
	for (; i < n1 && j < n2; ++pos)
	{
		if (left[i] <= right[j])
			*pos = left[i++];
		else
			*pos = right[j++];
	}
	while (i < n1) {
		*pos = left[i++];
		++pos;
	}
	while (j < n2) {
		*pos = right[j++];
		++pos;
	}
}

template <typename T>
void mergesort(T &nums, int low, int high)
{
	if (low < high) {
		int mid = low + (high - low) / 2;
		mergesort(nums, low, mid);
		mergesort(nums, mid + 1, high);
		merge(nums, low, mid, high);
	}
	return;
}

#endif