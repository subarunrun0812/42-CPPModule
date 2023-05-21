#include "phonebook.hpp"

//メンバイニシャライザ
PhoneBook::PhoneBook() : firstName(""), lastName(""), \
nickname(""), phoneNumber(""), darkestSecret("")
{
    
}


std::string PhoneBook::getter_firstName(void)
{
    return (PhoneBook::firstName);
}