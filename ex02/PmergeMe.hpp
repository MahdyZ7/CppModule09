#ifndef PMERGEME_HPP
#define PMERGE_HPP

#include <iostream>
#include <vector>
#include <list>
#include <sstream>

typedef std::vector<size_t> vector;
typedef std::list<std::pair<int,int> > mylist;

bool is_valid(const std::string& str);

template <typename T>
void merge(T &nums, int low, int mid, int high);

template <typename T>
void mergesort(T &nums, int low, int high);

template <typename T>
void printnums(T lst);

template <class T = mylist, class  F = std::list<int> >
class PMM
{
	public:
		PMM();
		explicit  PMM(const std::string& str);
		explicit  PMM(char** chrarr);
		PMM(const PMM& other);
		~PMM();

		PMM& operator=(const PMM& other);
		// void sortVector() const;
		// void sortVector1() const;
		// void sortListPairs() const;
		void sort();
	
	private:
		std::string str;
	
};

#endif