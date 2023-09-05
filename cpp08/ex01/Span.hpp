#ifndef SPAN_HPP
#define SPAN_HPP

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define NORMAL "\x1b[0m"
#define LINE "=========="
#define LENGTH 4

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

/* TODO:
 Span = 2つの整数の差\
 最大N個の整数を格納できる
 Nはunsigned int変数
 コンストラクタ(unsigned int 変数名)
 メンバ関数
  addNumber()\
要素を満たすために、文字を一つ追加する。\
もし、既にN個の要素が格納された状態で、要素を追加しようとすると例外がthrowされる
 shortestSpan()\
最短Spanのを返す(int)。\
例)整数のセット{1, 3, 8, 9, 10}がある場合、\
最も小さい距離は1（9と10の間、または8と9の間）です。
 longestSpan()\
最長Spanを返す(int)。
 格納されているspanが1以下なら例外がthrowされる。
 10000の数字を使って、スパンをテストする。
  イテレーターの範囲を使って、spanを埋める事が推奨される。\
addNumber()を何度も呼び出すのは面倒なので、メンバ関数の1回の呼び出しで多くの数値をSpanに追加しましょう。
*/
class Span
{
private:
    std::vector<int> _vec;
    unsigned int _size;

public:
    Span();
    Span(unsigned int num);
    ~Span();
    Span(const Span &span);
    Span &operator=(const Span &span);
    void addNumber(const int num);
    int shortestSpan();
    int longestSpan();
    int SmallestNumber();
    int LargestNumber();

    //========== 例外クラス ==========
    class NotEnoughElement : public std::exception
    {
        const char *what() const throw()
        {
            return (RED "要素数が1個以下の為、探索出来ません💢💢" NORMAL);
        }
    };
};

#endif