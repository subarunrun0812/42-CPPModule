#include "phonebook.hpp"


void PhoneBook::empty_error(void)
{
    std::cout << "\x1b[31mError:empty string\x1b[0m" << std::endl;
    ft_add();
}

// 連絡先の情報を追加するよう促す
void PhoneBook::ft_add(void)
{
    
    std::string firstName;
    std::cout << "Input" << std::endl;
    std::cout << "first name    : " && std::cin >> firstName;
    //TODO:emptyの条件式に入らない
    if (firstName.empty())
    {
        std::cout << "から" << std::endl;
        empty_error();
    }
    setFirstName(firstName);

    std::string lastName;
    std::cout << "last name     : " && std::cin >> lastName;
    if (lastName.empty())
        empty_error();
    setLastName(lastName);

    std::string nickName;
    std::cout << "nick name     : " && std::cin >> nickName;
    if (nickName.empty())
        empty_error();
    setNickName(nickName);

    std::string phoneNumber;
    std::cout << "phone number  : " && std::cin >> phoneNumber;
    if (phoneNumber.empty())
        empty_error();
    setPhoneNumber(phoneNumber);

    std::string darkestSecret;
    std::cout << "darkest secret: " && std::cin >> darkestSecret;
    if (darkestSecret.empty())
        empty_error();
    setDarkestSecret(darkestSecret);
}