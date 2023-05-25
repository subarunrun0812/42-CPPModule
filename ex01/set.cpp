#include "phonebook.hpp"


void PhoneBook::setFirstName(std::string str)
{
    //firstNameの値を更新できるのは、この関数がその変数と同じクラスで定義されているから
    firstName = str;
}

void PhoneBook::setLastName(std::string str)
{
     lastName = str;
}

void PhoneBook::setNickName(std::string str)
{
     nickname = str;
}

void PhoneBook::setPhoneNumber(std::string str)
{
     phoneNumber = str;
}

void PhoneBook::setDarkestSecret(std::string str)
{
     darkestSecret = str;
}