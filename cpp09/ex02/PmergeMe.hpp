#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define NORMAL "\x1b[0m"
#define LINE "=========="
#define SUCCESS 0
#define FAILE 1

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>

/*
TODO:
引数として、正の整数を複数受け取る
それらをソートするために、マージインサートソードアルゴリズムを使用する
Ford-Johson algorithm
プログラム実行中にエラーが発生したら、エラーメッセージを表示する。
3000種類の正の整数が来ても、ソートできるようにする
出力:
1行目=ソートされていない整数を表示
2行目=ソートされた整数を表示
3行目=使用したコンテナとアルゴリズムの計算時間を表示
4行目=使用したコンテナとアルゴリズムの計算時間を表示
*/

class PmergeMe
{
private:
    std::vector<int> _vec;
    std::list<int> _list;

public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &pmergeme);
    PmergeMe &operator=(const PmergeMe &pmergeme);
    void AssingToVector(int argc, const char **argv);
    void AssingToList(int argc, const char **argv);
    void MergeInsertionSort_Vector();
    void MakePairs(std::vector<std::pair<int, int> > &pairs);
    void SortPair(std::vector<std::pair<int, int> > pairs);
    void AssignToLargeAndSmallList(std::vector<std::pair<int, int> > pairs,\
    std::vector<int> &smallVec, std::vector<int> &largeVec);
    // debug用
    void ShowVector(std::string str,std::vector<int> vec);
};

class ErrorParametor : public std::exception
{
    const char *what() const throw()
    {
        return (RED "Error: 無効な引数が含まれている" NORMAL);
    }
};

#endif