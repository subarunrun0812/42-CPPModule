#include "phonebook.hpp"

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
            phonebook.add_contact();
        else if (cmd == "SEARCH" || cmd == "search")
            phonebook.view_contact();
        else if (cmd == "EXIT" || cmd == "exit")
            break;
        else if (std::cin.eof())
        {
            //ctrl-dが押された時
            std::cin.clear();
            return (1);
        }
        else if (cmd.empty())
        {
            std::cin.clear();
        }
        else
        {
            std::cout << "Command is incorrect." << std::endl;
        }
    }
    return (0);
}