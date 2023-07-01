#ifndef PMERGEME_HPP
#define PMERGE_HPP

#include <iostream>
#include <vector>
#include <sstream>

typedef std::vector<size_t> vector;
class PMM
{
	public:
		PMM();
		PMM(const std::string& str);
		PMM(char** chrarr);
		PMM(const PMM& other);
		~PMM();

		PMM& operator=(const PMM& other);
		void sortVector() const;
		void sortVector1() const;
		void sortVectorPairs() const;
	
	private:
		std::string str;
	
};
#endif