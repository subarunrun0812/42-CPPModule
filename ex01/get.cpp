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