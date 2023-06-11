#include "phonebook.hpp"

//TODO: 8つの連絡先を保存できるようにする
int main(void)
{
    Contact contact;//Contactクラスのインスタンスを作成
    PhoneBook phonebook;//phonebookクラスのインスタンスを作成
    std::string cmd;
    while (true)
    {
        std::cout << "\x1b[32mEnter command (ADD, SEARCH, EXIT)\x1b[0m" << std::endl;
        std::cout << ">";
        std::getline(std::cin, cmd);

        if (cmd == "ADD" || cmd == "add")
            contact.ft_add();
        else if (cmd == "SEARCH" || cmd == "search")
            contact.ft_view();
        else if (cmd == "EXIT" || cmd == "exit")
            break;
        else
            std::cout << "Command is incorrect." << std::endl;
    }
    return (0);
}