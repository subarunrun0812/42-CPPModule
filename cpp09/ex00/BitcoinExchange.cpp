#include "BitcoinExchange.hpp"

BX::BX()
{
}

BX::~BX()
{
}

BX::BX(const BX& bx)
{
	_map = bx._map;
}

BX& BX::operator=(const BX& bx)
{
	_map = bx._map;
	return (*this);
}

float BX::stringToFloat(const std::string& str)
{
	std::istringstream iss(str);
	float fl;
	if (!(iss >> fl))
	{
		std::cout << "\"" << str << "\"";
		throw TypeConversionFailure();
	}
	return fl;
}

int BX::stringToInt(const std::string& str)
{
	std::istringstream iss(str);
	int num;
	if (!(iss >> num))
	{
		std::cout << "\"" << str << "\"";
		throw TypeConversionFailure();
	}
	return num;
}

void BX::DataTokenize(std::string line)
{
	int pos = line.find(',');
	std::string key = line.substr(0, pos);
	std::string valueStr = line.substr(pos + 1);
	try
	{
		float value = stringToFloat(valueStr);
#ifdef DEBUG
		std::cout << "_map[" << key << "]"
			<< " = " << value << std::endl;
#endif
		_map[key] = value;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED "data.csvで" << e.what() << '\n';
	}
}

float BX::fetchNearestValue(const std::string& dataStr)
{
	std::map<std::string, float>::iterator it = _map.lower_bound(dataStr);
	// dataStr より前の最も近い日付
	if (it != _map.begin())
		--it;
	return it->second;
}

float BX::validateNumber(const std::string& data)
{
	size_t pos = data.find("|");
	if (pos == std::string::npos)
	{
		std::cout << RED "Error: data or value is missing" NORMAL << std::endl;
		throw ErrorData();
	}
	std::string numberStr = data.substr(pos + 1);
	size_t startNumber = numberStr.find_first_not_of(" \t");
	if (startNumber != std::string::npos)
	{
		numberStr = numberStr.substr(startNumber);
	}
	float number = stringToFloat(numberStr);
	if (number < 0)
		throw SmallANumber();
	if (1000 < number)
		throw LargeANumber();

	return number;
}

void BX::IsValidDataYearMonthDay(size_t year, size_t month, size_t day)
{
	(void)year;
	if ((1 <= month && month <= 12) && (1 <= day))
	{
		if (1 == month)
			if (31 < day)
				throw ErrorData();
		if (2 == month)
			if (28 < day)
				throw ErrorData();
		if (3 == month)
			if (31 < day)
				throw ErrorData();
		if (4 == month)
			if (30 < day)
				throw ErrorData();
		if (5 == month)
			if (31 < day)
				throw ErrorData();
		if (6 == month)
			if (30 < day)
				throw ErrorData();
		if (7 == month)
			if (31 < day)
				throw ErrorData();
		if (8 == month)
			if (31 < day)
				throw ErrorData();
		if (9 == month)
			if (30 < day)
				throw ErrorData();
		if (10 == month)
			if (31 < day)
				throw ErrorData();
		if (11 == month)
			if (30 < day)
				throw ErrorData();
		if (12 == month)
			if (31 < day)
				throw ErrorData();
	}
	else
		throw ErrorData();
}
void BX::IsValidDataFind(size_t pos)
{
	if (pos == std::string::npos)
	{
		std::cout << "IsValidDataFind()" << std::endl;
		throw ErrorData();
	}
}
void BX::tokenizeDate(const std::string& data, size_t& year, size_t& month, size_t& day)
{
	// 年
	size_t yearPos = data.find('-');
	IsValidDataFind(yearPos);
	std::string yearStr = data.substr(0, yearPos);
	year = stringToInt(yearStr);
	// 月
	size_t monthPos = data.find('-', yearPos + 1);
	IsValidDataFind(monthPos);
	std::string monthStr = data.substr(yearPos + 1, monthPos);
	month = stringToInt(monthStr);
	// 日
	std::string dayStr = data.substr(monthPos + 1);
	day = stringToInt(dayStr);


#ifdef DEBUG
	std::cout << "year:" << year << std::endl;
	std::cout << "month:" << month << std::endl;
	std::cout << "day:" << day << std::endl;
#endif
}

void BX::IsValidData(std::string data)
{
	try
	{
		size_t year, month, day;
		tokenizeDate(data, year, month, day);
		IsValidDataYearMonthDay(year, month, day);
		float number = validateNumber(data);

		std::string dataStr = data.substr(0, data.find("|"));
		float value = fetchNearestValue(dataStr);

		std::cout << GREEN << dataStr << "=> " << number
			<< " = " << number * value << NORMAL << std::endl;
	}
	catch (ErrorData& e)
	{
		std::cerr << e.what() << " => " << data << std::endl;
	}
	catch (LargeANumber& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (SmallANumber& e)
	{
		std::cerr << e.what() << std::endl;
	}
}



void BX::Read_File(std::string fileName, void (BX::* tokenizeFunc)(std::string))
{
	std::ifstream inFile(fileName);
	if (!inFile)
	{
		std::cout << RED "Unable to open input file:"
			<< fileName << NORMAL << std::endl;
	}
	int count = 0;
	std::string line;
	while (std::getline(inFile, line))
	{
		if (count == 0)
			;
		else
			(this->*tokenizeFunc)(line);
		count++;
	}
}

int BX::Currency(std::string fileName)
{
	Read_File("data.csv", &BX::DataTokenize);
	Read_File(fileName, &BX::IsValidData);
	return (SUCCESS);
}