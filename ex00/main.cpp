#include "BitcoinExchange.hpp"

void print_map(std::string comment, const mymap& m)
{
	std::cout << comment;
	for (mymap::const_iterator it = m.begin(); it != m.end(); it++)
    	std::cout << it->first << " = " << it->second << ";\n";
}

int main(int argv, char ** argc)
{
	if (argv != 2)
	{
		std::cout << "invalid number of arguments\n";
		return 0;
	}

	try
	{
		BTC btc;
		btc.convert(argc[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}