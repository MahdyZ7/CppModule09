#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/stat.h>




typedef std::map<std::string , double, std::greater<std::string> > mymap;
class BTC
{
	public:
		BTC();
		BTC(const std::string& data);
		BTC(const BTC& other);
		~BTC();

		BTC &operator=(const BTC& other);

		void convert(const std::string& file);
		void populateMap(const std::string& file);
	
	private:
		#define  datafile "data.csv"
		mymap m;
};


#endif