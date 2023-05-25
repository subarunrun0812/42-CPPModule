#include "phonebook.hpp"

void PhoneBook::ft_search(void)
{
    // 連絡先を全て表示
    std::cout << "====== INFO ======" << std::endl;
    std::cout << "firstname :" << getFirstName() << std::endl;
    std::cout << "lastname :" << getLastName() << std::endl;
    std::cout << "nickname :" << getNickName() << std::endl;
    std::cout << "phone number :" << getPhoneNumber() << std::endl;
    std::cout << "darkest secret :" << getDarkestSecret() << std::endl;
}