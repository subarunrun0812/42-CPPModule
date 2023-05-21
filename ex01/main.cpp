#include "phonebook.hpp"

int main(void)
{
    PhoneBook phoneBook;//PhoneBookクラスのインスタンスを作成
    std::string first_name;
    first_name = phoneBook.getter_firstName();
    std::cout << first_name << std::endl;
}