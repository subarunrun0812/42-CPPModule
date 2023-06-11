#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}


void PhoneBook::add_contact(void)
{
    static int i;
    this->contacts[i % MAX_SIZE].ft_add();
    i++;
}

void PhoneBook::view_contact(void)
{
    int i = 0;
    while (i < MAX_SIZE)
    {
        // if (this->contacts[i] == NULL)
        //     break;
        this->contacts[i].ft_view();
        i++;
    }
}