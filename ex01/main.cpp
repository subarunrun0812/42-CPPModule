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

        if (cmd == "")
            ;
        else if (cmd == "ADD")
            ft_add();
        else if (cmd == "SEARCH")
            ft_search();
        else if (cmd == "EXIT")
            break;
        else
            std::cout << "Please enter ADD, SEARCH, or EXIT" << std::endl;
    }
    return (0);
}