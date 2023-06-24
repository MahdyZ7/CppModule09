#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <iomanip>


class RPN
{
	public:
		RPN();
		RPN(const RPN& other);
		RPN(const std::string& str);
		~RPN();

		RPN& operator=(const  RPN&other);

		void postfix();
	private:
		std::string exp;

};
#endif