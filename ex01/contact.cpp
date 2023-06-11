#include "phonebook.hpp"

//クラスの初期化にデフォルトコンストラクタを使用
Contact::Contact()
{
}

Contact::~Contact()
{
}

// constをつけることでオブジェクトの状態を変化しない事を明示的に示す
std::string Contact::getFirstName(void) const
{
    return (Contact::firstName);
}

std::string Contact::getLastName(void) const
{
    return (Contact::lastName);
}

std::string Contact::getNickName(void) const
{
    return (Contact::nickname);
}

std::string Contact::getPhoneNumber(void) const
{
    return (Contact::phoneNumber);
}

std::string Contact::getDarkestSecret(void) const
{
    return (Contact::darkestSecret);
}

void Contact::setFirstName(std::string str)
{
    //firstNameの値を更新できるのは、この関数がその変数と同じクラスで定義されているから
    firstName = str;
}

void Contact::setLastName(std::string str)
{
     lastName = str;
}

void Contact::setNickName(std::string str)
{
     nickname = str;
}

void Contact::setPhoneNumber(std::string str)
{
     phoneNumber = str;
}

void Contact::setDarkestSecret(std::string str)
{
     darkestSecret = str;
}

void Contact::empty_error(void)
{
    std::cout << "\x1b[31mError:empty string\x1b[0m" << std::endl;
    ft_add();
}

// 連絡先の情報を追加するよう促す
void Contact::ft_add(void)
{
    std::string firstName;
    std::cout << "Input" << std::endl;
    std::cout << "first name    : ";
    std::getline(std::cin, firstName);
    //TODO:emptyの条件式に入らない
    if (firstName.empty())
    {
        std::cout << "から" << std::endl;
        empty_error();
    }
    setFirstName(firstName);

    std::string lastName;
    std::cout << "last name     : ";
    std::getline(std::cin, lastName);
    // if (lastName.empty())
    //     empty_error();
    setLastName(lastName);

    std::string nickName;
    std::cout << "nick name     : ";
    std::getline(std::cin, nickName);
    // if (nickName.empty())
    //     empty_error();
    setNickName(nickName);

    std::string phoneNumber;
    std::cout << "phone number  : ";
    std::getline(std::cin, phoneNumber);
    // if (phoneNumber.empty())
    //     empty_error();
    setPhoneNumber(phoneNumber);

    std::string darkestSecret;
    std::cout << "darkest secret: ";
    std::getline(std::cin, darkestSecret);
    // if (darkestSecret.empty())
    //     empty_error();
    setDarkestSecret(darkestSecret);
}

void Contact::ft_view(void)
{
    int i;
    i = 0;

    // 連絡先を全て表示
    std::cout << "====== INFO ======" << std::endl;
    std::cout << "firstname :" << getFirstName() << std::endl;
    std::cout << "lastname :" << getLastName() << std::endl;
    std::cout << "nickname :" << getNickName() << std::endl;
    std::cout << "phone number :" << getPhoneNumber() << std::endl;
    std::cout << "darkest secret :" << getDarkestSecret() << std::endl;
}
