#include "phonebook.hpp"

int main(void)
{
    PhoneBook phoneBook;//PhoneBookクラスのインスタンスを作成
    std::string cmd;
    while (true)
    {
        std::cout << "\x1b[32mEnter command (ADD, SEARCH, EXIT)\x1b[0m" << std::endl;
        std::cout << ">";
        std::cin >> cmd;

        if (cmd == "ADD" || cmd == "add")
            phoneBook.ft_add();
        else if (cmd == "SEARCH" || cmd == "search")
            phoneBook.ft_search();
        else if (cmd == "EXIT" || cmd == "exit")
            break;
        else
            std::cout << "Command is incorrect." << std::endl;
    }
    return (0);
}