#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <iomanip>


class RPN
{
	RPN();
	RPN(const RPN& other);
	RPN(const std::string& str);

	RPN& operator=(const  RPN&other);
	~RPN();

	private:
		std::string exp;
		int result;

};
#endif