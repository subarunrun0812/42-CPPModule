#include "BitcoinExchange.hpp"

float stringToFloat(const std::string& str)
{
	std::istringstream iss(str);
	float fl;
	iss >> fl;
	return fl;
}

void BitcoinExchange::DataTokenize(std::string line)
{
	int pos = line.find(',');
	std::string key = line.substr(0, pos);
	std::string valueStr = line.substr(pos + 1);

	float value = stringToFloat(valueStr);
	std::cout << "_map[" << key << "]" << " = " << value << std::endl;
	_map[key] = value;
}

void isValidData()
{

}

void NumberOfCurrencyTokenize(std::string line)
{
	size_t pos = line.find("|");
	if (pos == std::string::npos)
	{
		std::cout << RED "Error: data or value is missing" NORMAL << std::endl;
	}
	std::string key = line.substr(0, pos);
	std::string valueStr = line.substr(pos + 1);
	//日付のチェック


	//有効な数値のチェック(0~1000)

}

void BitcoinExchange::NumberOfCurrency(std::string fileName)
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
			NumberOfCurrencyTokenize(line);
		count++;
	}
}

int BitcoinExchange::EditFile(std::string fileName)
{
	// data.csv
	std::ifstream inFile("data.csv");
	if (!inFile)
	{
		std::cout << RED "Unable to open input file:"
			<< "data.csv" << NORMAL << std::endl;
	}

	std::string line;
	while (std::getline(inFile, line))
	{
		DataTokenize(line);
	}

	//input.txt
	NumberOfCurrency(fileName);
	return (SUCCESS);
}

int main(int argc, char const* argv[])
{
	if (argc < 2)
	{
		std::cout << RED "Error: could not open file." NORMAL << std::endl;
	}
	else if (argc == 2)
	{
		BitcoinExchange bx;
		bx.EditFile(argv[1]);
	}
	else
	{
		std::cout << RED "Error: too many arguments." NORMAL << std::endl;
	}
	return 0;
}
