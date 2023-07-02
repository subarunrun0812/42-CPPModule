#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

// 小文字を大文字に変換する
char my_toupper(char ch)
{
    return (std::toupper(ch));
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    int i = 1;
    while (i < argc)
    {
        int j = 0;
        while (argv[i][j] != '\0')
        {
            std::cout << my_toupper(argv[i][j]);
            j++;
        }
        i++;
		if (i < argc)
			std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}