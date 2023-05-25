#include "phonebook.hpp"

//メンバイニシャライザ　初期化
PhoneBook::PhoneBook() : firstName(""), lastName(""), \
nickname(""), phoneNumber(""), darkestSecret("")
{
    
}


// constをつけることでオブジェクトの状態を変化しない事を明示的に示す
std::string PhoneBook::getFirstName(void) const
{
    return (PhoneBook::firstName);
}

std::string PhoneBook::getLastName(void) const
{
    return (PhoneBook::lastName);
}

std::string PhoneBook::getNickName(void) const
{
    return (PhoneBook::nickname);
}

std::string PhoneBook::getPhoneNumber(void) const
{
    return (PhoneBook::phoneNumber);
}

std::string PhoneBook::getDarkestSecret(void) const
{
    return (PhoneBook::darkestSecret);
}
