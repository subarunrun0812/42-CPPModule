#include "phonebook.hpp"

// 連絡先の情報を追加するよう促す
void PhoneBook::ft_add(void)
{
    
    std::string firstName;
    std::cout << "Input" << std::endl;
    std::cout << "first name    : " && std::cin >> firstName;
    setFirstName(firstName);

    std::string lastName;
    std::cout << "last name     : " && std::cin >> lastName;
    setLastName(lastName);

    std::string nickName;
    std::cout << "nick name     : " && std::cin >> nickName;
    setNickName(nickName);

    std::string phoneNumber;
    std::cout << "phone number  : " && std::cin >> phoneNumber;
    setPhoneNumber(phoneNumber);

    std::string darkestSecret;
    std::cout << "darkest secret: " && std::cin >> darkestSecret;
    setDarkestSecret(darkestSecret);
}