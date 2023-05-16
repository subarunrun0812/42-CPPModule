#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

int main()
{
    std::ifstream ifs("test1.txt");
    if (!ifs) {
        std::cerr << "test1 ファイルオープンに失敗" << std::endl;
        std::exit(1);
    }

    std::ofstream ofs("test2.txt");
    if (!ofs) {
        std::cerr << "test2 ファイルオープンに失敗" << std::endl;
        std::exit(1);
    }

    char c;
    while (ifs.get(c)) {
        ofs << c;
    }
    if (!ifs.eof()) {
        std::cerr << "読み込みに失敗" << std::endl;
        std::exit(1);
    }

    ofs << std::flush;
}