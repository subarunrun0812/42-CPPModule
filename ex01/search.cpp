#include "phonebook.hpp"

void ft_search(void)
{
    // 連絡先を全て表示
    // TODO:直接privateアクセスの変数の値を変えたいので、ここでインスタンスを生成してはいけない
    PhoneBook phoneBook;//PhoneBookクラスのインスタンスを作成
    std::cout << "=== INFO ===";
    std::cout << phoneBook.getFirstName() << std::endl;
}