#include "phonebook.hpp"

// 連絡先の情報を追加するよう促す
void ft_add(void)
{
    // TODO:直接privateアクセスの変数の値を変えたいので、ここでインスタンスを生成してはいけない
    PhoneBook phoneBook;//PhoneBookクラスのインスタンスを作成
    std::string first_name;
    std::cout << "Enter first name: " && std::cin >> first_name;
    phoneBook.setFirstName(first_name);
    // std::cout << phoneBook.getFirstName() << std::endl;
}