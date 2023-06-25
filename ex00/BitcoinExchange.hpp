#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/stat.h>

#define  datafile "data.csv"

typedef std::map<std::string , double, std::greater<std::string> > mymap;

class BTC
{
	public:
		BTC();
		BTC(const std::string& data);
		BTC(const BTC& other);
		~BTC();

		BTC &operator=(const BTC& other);

		void convert(const std::string& file) const;
		void populateMap(const std::string& file);
		double getRate(const std::string& str) const;
	
	private:
		static float isFloat(const std::string& str, bool max);
		static bool isDate(const std::string& str);
		static bool isValidDate(const std::string& str);
		mymap m;
};


#endif