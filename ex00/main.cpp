#include "BitcoinExchange.hpp"

void print_map(std::string comment, const std::map<std::string, float>& m)
{
	std::cout << comment;
	for (std::map<std::string, float>::const_iterator it = m.begin(); it != m.end(); it++)
    	std::cout << it->first << " = " << it->second << ";\n";
}

int main(int argv, char ** argc)
{
	if (argv != 2)
	{
		std::cout << "invalid number of arguments\n";
		return 0;
	}

	std::string line, date, rate;
	std::fstream exrate(argc[1], std::ios::in);
	std::map<std::string, float> m;
	if (exrate.is_open())
	{
		getline(exrate, line);
		while (getline(exrate, line)) {
    		std::stringstream str(line);
			getline(str, date, ',');
			getline(str, rate, ',');
			m[date] = std::stof(rate);
		}
		print_map("", m);

	}
	else
	{
		std::cout << "Input file unreadable\n";
	}

}