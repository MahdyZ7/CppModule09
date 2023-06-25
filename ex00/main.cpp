#include "BitcoinExchange.hpp"

void print_map(std::string comment, const mymap& m)
{
	std::cout << comment;
	for (mymap::const_iterator it = m.begin(); it != m.end(); it++)
    	std::cout << it->first << " = " << it->second << ";\n";
}

int main(int argv, char ** argc)
{
	// double x = 0.03;
	// std::cout << x;
	// return 0;
	if (argv != 2)
	{
		std::cout << "invalid number of arguments\n";
		return 0;
	}

	std::string line, date, rate;
	std::fstream exrate(argc[1], std::ios::in);
	mymap m;
	// return 0;
	// struct stat buffer;
	// stat(argc[1], &buffer);
  	// if (S_ISREG(buffer.st_mode))
	// 	std::cout << "file is a directory\n";
	// else
	// 	std::cout << "file is a file\n";
	// return 0;
	if (exrate.is_open() )
	{
		getline(exrate, line);
		while (getline(exrate, line)) {
    		std::stringstream str(line);
			getline(str, date, ',');
			getline(str, rate, ',');
			m[date] = std::stof(rate);
		}
		print_map("", m);

		
		std::pair<mymap::iterator,mymap::iterator> ret;
  		ret = m.equal_range("3022-02-26");

		mymap::iterator ll = m.lower_bound("3022-02-26");
		std::cout << "New lower bound " << ll->first << " ";
		std::cout <<  ll->second<< std::endl;
		std::cout << "lower bound " << ret.first->first << " ";
		std::cout <<  ret.first->second<< std::endl;
		if (ret.first->first == "")
			std::cout<< "use end\n";
		std::cout << "upper bound " << ret.second->first << " ";
		std::cout <<  ret.second->second<< std::endl;

	}
	else
	{
		std::cout << "Input file unreadable\n";
	}

}