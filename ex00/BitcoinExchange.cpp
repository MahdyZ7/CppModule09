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
	std::fstream exrate(file, std::ios::in);
	struct stat buffer;

	stat(file.c_str(), &buffer);
	if (S_ISREG(buffer.st_mode) && exrate.is_open())
	{
		m.clear();
		getline(exrate, line);
		while (getline(exrate, line)) {
    		std::stringstream str(line);
			getline(str, date, ',');
			getline(str, rate, ',');
			m[date] = std::stod(rate);
		}
		exrate.close();
		return;
	}
	throw("Invalid database \"" + file + "\"\n");
	
}

static float isfloat(std::string str)
{
	int		num;
	size_t	dec = 0;

	for(int i = 0; str[i]; ++i)
	{
		if (std::isdigit(str[i]))
			continue;
		else if (str[i] == '.' && dec == 0)
		{
			++dec;
			continue;
		}
		return -1;
	}
	num = std::stof(str);
	if (num < 0)
		return(-2);
	else if (num > 1000.0)
		return -3;
	return num;
}

static bool isvaliddate(std::string str)
{
	std::string			word;
	int					date[3]; 
	std::stringstream	ss(str);

	for(int i = 0; i < 3; ++i)
	{
		std::getline(ss, word, '-');
		std::stringstream s_temp(word);
		s_temp >> date[i];
		if (date[i] <= 0)
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
static bool isdate(std::string str)
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

void BTC::convert(const std::string& file)
{
	std::string line, date, stramount;
	std::fstream exrate(file, std::ios::in);
	struct stat buffer;

	stat(file.c_str(), &buffer);
	if (!(S_ISREG(buffer.st_mode) && exrate.is_open()))
	{
		std::cout << "\"" << file << "\" could not be opend\n";
		exrate.close();
		return ;
	}
	getline(exrate, line);
	while (getline(exrate, line)) {
		try
		{
			std::stringstream str(line);
			std::string temp;
			if (!(str >> date && str >> temp && str >> stramount))
				throw(std::invalid_argument("Error: bad input format"));
			if (!isdate(date) || !isvaliddate(date))
				throw(std::invalid_argument("Error: bad input =>" + date));
			if (temp != "|")
				throw(std::invalid_argument("Error: bad input format"));
			float sol = isfloat(stramount);
			if (sol < 0)
			{
				if (sol == -1)
					throw(std::invalid_argument("Error: Not a numebr"));
				else if (sol == -2)
					throw(std::invalid_argument("Error: not a positive number."));
				throw(std::invalid_argument("Error: Out of range number.\n"));
			}
			std::cout << date << " => " << stramount << " = " << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	exrate.close();
	return;
}