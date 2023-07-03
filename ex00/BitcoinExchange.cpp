#include "BitcoinExchange.hpp"

BTC::BTC()
{
	populateMap(datafile);
}

BTC::BTC(const std::string& data)
{
	populateMap(data);
}

BTC::BTC(const BTC& other): m(other.m){}

BTC::~BTC(){}

BTC &BTC::operator=(const BTC& other)
{
	m = other.m;
	return *this;
}

void BTC::populateMap(const std::string& file)
{
	std::string line, date, rate;
	std::fstream exrate(&file[0], std::ios::in);
	struct stat buffer;
	double d;

	stat(file.c_str(), &buffer);
	if (S_ISREG(buffer.st_mode) && exrate.is_open())
	{
		m.clear();
		getline(exrate, line);
		if (line != "date,exchange_rate")
			throw std::invalid_argument("Error: database is corupt\n");
		while (getline(exrate, line)) {
    		std::stringstream str(line);
			getline(str, date, ',');
			getline(str, rate, ',');
			if (!(isDate(date) && isFloat(rate, false) >= 0 && isValidDate(date)))
			{
				std::cout << "Invalid: " << date << " " << rate << std::endl;
				throw(std::invalid_argument("Error: database is corrupt"));
			}
			std::stringstream(rate) >> d;
			m[date] = d;
		}
		exrate.close();
		return;
	}
	throw(std::invalid_argument("Error: could not open file."));
}

double BTC::isFloat(const std::string& str, bool max)
{
	double	num;
	size_t	dec = 0;

	for(int i = 0; str[i]; ++i)
	{
		if (str[i] == '-' && i == 0)
			continue;
		if (std::isdigit(str[i]))
			continue;
		else if (str[i] == '.' && dec == 0)
		{
			++dec;
			continue;
		}
		throw(std::invalid_argument("Error: not a number"));
	}
	std::stringstream(str) >> num;
	if (num < 0)
		throw(std::invalid_argument("Error: not a positive number."));
	else if (num > 1000.0 && max)
		throw(std::invalid_argument("Error: too large a number."));
	return num;
}

bool BTC::isValidDate(const std::string& str)
{
	std::string			word;
	int					date[3]; 
	std::stringstream	ss(str);

	for(int i = 0; i < 3; ++i)
	{
		std::getline(ss, word, '-');
		std::stringstream s_temp(word);
		s_temp >> date[i];
		if (date[i] <= 0 && i != 0)
			return false;
	}
	if (date[1] > 12 || date[2] > 31)
		return false;
	if (date[1] >= 8)
		++date[1];
	if (date[1] % 2 == 0 && date[2] > 30)
		return false;
	if (date[1] != 2)
		return true;
	if (date[0] % 400 == 0 || (date[0] % 100 != 0  && date[0] % 4 == 0))
		--date[2];
	if (date[1] == 2 && date[2] > 28)
		return false;
	return true;
}

bool BTC::isDate(const std::string& str)
{
	size_t	dash = 0;
	size_t	i = 0;

	while (true)
	{
		if(!std::isdigit(str[i]))
			return false;
		for(int num_len = 0; str[i]; ++i, ++num_len)
		{
			if (num_len > 4)
				return false;
			if (!std::isdigit(str[i]))
				break;
		}
		if (!str[i] && dash == 2)
			break;
		if (str[i] == '-' && dash < 2)
		{
			++dash;
			++i;
			continue;
		}
		return false;
	}
	return true;
}

double BTC::getRate(const std::string& date) const
{
	mymap::const_iterator it = m.lower_bound(date);
	if (it == m.end())
		return 0;
	return it->second;
}

void BTC::convert(const std::string& file) const
{
	std::string line, date, stramount;
	std::fstream exrate(&file[0], std::ios::in);
	struct stat buffer;

	stat(file.c_str(), &buffer);
	if (!(S_ISREG(buffer.st_mode) && exrate.is_open()))
	{
		std::cout << "Error: could not open file.\n";
		exrate.close();
		return ;
	}
	getline(exrate, line);
	if (line != "date | value")
		throw(std::invalid_argument("Error: invalid file format"));
	while (getline(exrate, line)) {
		try
		{
			if (line.empty())
			{
				std::cout << std::endl;
				continue;
			}
			std::stringstream str(line);
			std::string temp;
			if (!(str >> date && str >> temp && str >> stramount))
				throw(std::invalid_argument("Error: bad input => " + line ));
			if (!isDate(date) || !isValidDate(date))
				throw(std::invalid_argument("Error: bad date input => " + date));
			if (temp != "|")
				throw(std::invalid_argument("Error: bad input => " + line ));
			float sol = isFloat(stramount, true);
			std::cout << date << " => " << stramount << " = " << sol * getRate(date) <<std::endl ;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	exrate.close();
	return;
}