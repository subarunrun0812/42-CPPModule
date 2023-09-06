#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define NORMAL "\x1b[0m"
#define LINE "=========="
#define SUCCESS 0
#define ERROR 1

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>

/*
TODO:
プログラムは引数でファイルを受け取る
出力する際の形式: data | value
有効な日付の形式: Year-Month-Day
有効な値は、0~1000までの浮動小数点 or 正の整数
data.csvはビットコインの価値
input.txt。所持しているビットコインの数

step:
2つのファイルを開く
<data.csv>
各行をトークナイズして、std::mapコンテナでdataとvalueの
情報を格納する。

<input.txt>
input.txtの文字列が有効な値か判定する

A=input.txtの日付をdata.csvから見つける。無い場合は、その日付から近い日付を取得
所有しているビットコイン達の価値 = A * value
*/

class BX
{
private:
	std::map<std::string, float> _map;


public:
	BX();
	~BX();
	BX(const BX& bx);
	BX& operator=(const BX& bx);

	int Currency(std::string fileName);
	void Read_File(std::string fileName, void (BX::* tokenizeFunc)(std::string));
	void DataTokenize(std::string line);
	void NumberOfCurrencyTokenize(std::string line);
	// float fetchNearestValue(const std::string& dataStr);
	// float validateNumber(const std::string& data);
	// void tokenizeDate(const std::string& data, size_t& year, size_t& month, size_t& day);
	void IsValidData(std::string data);
	void IsValidDataFind(size_t pos);
	void IsValidDataYearMonthDay(size_t year, size_t month, size_t day);
	int stringToInt(const std::string& str);
	float stringToFloat(const std::string& str);

	class ErrorData : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return (RED "Error: bad input" NORMAL);
		}
	};
	class LargeANumber : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return (RED "Error: too large a number" NORMAL);
		}
	};
	class SmallANumber : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return (RED "Error: not a positive number" NORMAL);
		}
	};
	class TypeConversionFailure : public std::exception
	{
		const char* what() const throw()
		{
			return (RED "型変換に失敗した" NORMAL);
		}
	};
};

#endif