#include "BitcoinExchange.hpp"

float BX::stringToFloat(const std::string &str)
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

int BX::stringToInt(const std::string &str)
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
    catch (const std::exception &e)
    {
        std::cerr << RED "data.csvで" << e.what() << '\n';
    }
}

void BX::IsValidDataFind(size_t pos)
{
    if (pos == std::string::npos)
        throw ErrorData();
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

void BX::IsValidData(std::string data)
{
    try
    {
        // 年
        size_t yearPos = data.find('-');
        IsValidDataFind(yearPos);
        std::string yearStr = data.substr(0, yearPos);
        size_t year = stringToInt(yearStr);
        // 月
        size_t monthPos = data.find('-');
        IsValidDataFind(monthPos);
        std::string monthStr = data.substr(yearPos + 1, monthPos);
        size_t month = stringToInt(monthStr);
        // 日
        size_t dayPos = data.find('-');
        IsValidDataFind(dayPos);
        std::string dayStr = data.substr(monthPos + 1, dayPos);
        size_t day = stringToInt(dayStr);
        IsValidDataYearMonthDay(year, month, day);
#ifdef DEBUG
        std::cout << "year:" << year << std::endl;
        std::cout << "month:" << month << std::endl;
        std::cout << "day:" << day << std::endl;
#endif

        // 有効な数値のチェック(0~1000)
        size_t pos = data.find("|");
        if (pos == std::string::npos)
        {
            std::cout << RED "Error: data or value is missing" NORMAL << std::endl;
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
        // std::cout << "number:" << number << std::endl;

        // 所有しているビットコイン群の価値
        std::string dataStr = data.substr(0, pos);
        // TODO: 保持している年月日に近いものをdata.csvから見つける
        float value = 10;
        std::cout << GREEN << dataStr << "=> " << number
                  << " = " << number * value << NORMAL << std::endl;
    }
    catch (ErrorData &e)
    {
        std::cerr << e.what() << " => " << data << std::endl;
    }
    catch (LargeANumber &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (SmallANumber &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void BX::NumberOfCurrencyTokenize(std::string line)
{
    // 日付の抽出 & チェック
    IsValidData(line);
}

void BX::NumberOfCurrency(std::string fileName)
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

int BX::EditFile(std::string fileName)
{
    // data.csv
    std::ifstream inFile("data.csv");
    if (!inFile)
    {
        std::cout << RED "Unable to open input file:"
                  << "data.csv" << NORMAL << std::endl;
    }

    std::string line;
    int count = 0;
    while (std::getline(inFile, line))
    {
        if (count == 0)
            ;
        else
            DataTokenize(line);
        count++;
    }

    // input.txt
    NumberOfCurrency(fileName);
    return (SUCCESS);
}

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cout << RED "Error: could not open file." NORMAL << std::endl;
    }
    else if (argc == 2)
    {
        BX bx;
        bx.EditFile(argv[1]);
    }
    else
    {
        std::cout << RED "Error: too many arguments." NORMAL << std::endl;
    }
    return 0;
}
