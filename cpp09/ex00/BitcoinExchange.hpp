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

class BitcoinExchange
{
private:
	std::map<std::string, float> _map;

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& bitcoinExchange);
	BitcoinExchange& operator=(const BitcoinExchange& bitcoinExchange);

	int EditFile(std::string fileName);
	void DataTokenize(std::string line);
	void NumberOfCurrency(std::string fileName);
	void NumberOfCurrencyTokenize(std::string line);
};

#endif