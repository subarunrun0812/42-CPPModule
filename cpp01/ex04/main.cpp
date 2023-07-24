#include <iostream>
#include <fstream>
#include <string>

std::string strReplace(std::string line, std::string s1, std::string s2)
{
	size_t pos = 0;
	//find(検索する文字列、検索を開始する位置) = 指定した部分文字列が文字列中のどの位置で最初に現れるかを探します.
	//std::string::findメソッドは、検索対象の部分文字列が見つからない場合、std::string::nposを返す。
	while (((pos = line.find(s1, pos)) != std::string::npos))
	{
		//posからs1の文字列分、lineの文字列を削除する。
		line.erase(pos, s1.length());
		//posからs2の文字列分、lineに文字列を複製する。
		line.insert(pos, s2);
		pos += s2.length();
	}
	return (line);
}

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "Missing argument" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];


	std::ifstream inFile(filename);
	if (!inFile)
	{
		std::cout << "Unable to open input file: " \
			<< filename << std::endl;
		return (1);
	}

	std::string line;
	std::string replacedContent;
	//fileから1行ずつ読み込んでいく
	while (std::getline(inFile, line)) {
		replacedContent += strReplace(line, s1, s2) + "\n";
	}
	inFile.close();

	std::ofstream outFile(filename + ".replace");
	if (!outFile)
	{
		std::cout << "Unable to open output file: " << filename + ".replace" << std::endl;
		return 1;
	}

	outFile << replacedContent;
	outFile.close();

	std::cout << "File contents replaced successfully" << std::endl;

	return 0;
}