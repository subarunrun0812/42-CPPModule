#ifndef ITER_HPP
#define ITER_HPP

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define NORMAL "\x1b[0m"
#define LINE "=========="
#define LENGTH 4

#include <iostream>

template <typename T>
void print(T &num)
{
    std::cout << num << std::endl;
}

template <typename T>
void iter(T *arr, size_t num, void (*func)(T &))
{
    for (size_t i = 0; i < num; i++)
    {
        func(arr[i]);
    }
}

#endif