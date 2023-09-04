#ifndef ARRAY_HPP
#define ARRAY_HPP

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define NORMAL "\x1b[0m"
#define LINE "=========="
#define LENGTH 4

#include <iostream>

/*
TODO:次のテンプレート関数を作成する
空の配列を作成する引数なしのデフォルトコンストラクタを作成。
unsigned int Nを引数とするコンストラクタ。n要素の配列を作成する
コピーコンストラクタ、コピー代入演算子を作成。コピー元とコピー後の配列のどちらかを変更しても
もう一方の配列には影響しない。
メモリ割り当ては new[] を使用する。
要素は添え字演算子でアクセスできる。
要素にアクセスした際、インデックスの範囲外だったら、std::exceptionにthrowされる
メンバ関数 size() は配列の要素数を返す。size()は引数なし。
*/

template <typename T>
class Array
{
private:
    T *_array;
    unsigned int _size; // 配列の要素数

public:
    Array() : _array(NULL), _size(0)
    {
    }
    Array(unsigned int n) : _size(n)
    {
        _array = new T[n];
    }
    ~Array()
    {
        delete[] _array;
    }
    Array(const Array &other)
    {
        this->_size = other._size;
        this->_array = new T[other._size];

        for (size_t i = 0; i < this->size(); i++)
        {
            this->_array[i] = other._array[i];
        }
    }
    Array &operator=(const Array &other)
    {
        delete this->_array;
        this->_size = other._size;
        this->_array = new T[other._size];

        for (size_t i = 0; i < this->_size; i++)
        {
            this->_array[i] = other._array[i];
        }
        return (*this);
    }
    // 添字演算子を追加
    T &operator[](unsigned int index)
    {
        if (index >= _size || !_array) // 範囲外のチェック
        {
            throw OutOfRange();
        }
        return _array[index];
    }

    unsigned int size() const
    {
        return (_size);
    }
    //================ 例外クラス ================
    class OutOfRange : public std::exception
    {
    public:
        const char *what() const throw() { return (RED "配列外にアクセスしようとした" NORMAL); }
    };
};

#endif