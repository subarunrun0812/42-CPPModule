#include "phonebook.hpp"

//クラスの初期化にデフォルトコンストラクタを使用
Contact::Contact()
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
    std::cout << "\x1b[31mError:empty string\x1b[0m" << std::endl << std::endl;
    ft_add();
}

// 連絡先の情報を追加するよう促す
void Contact::ft_add(void)
{
    std::string str;

    std::cout << "Input" << std::endl;
    std::cout << "first name    : ";
    std::getline(std::cin, str);
    if (str.empty())
        empty_error();
    setFirstName(str);

    std::cout << "last name     : ";
    std::getline(std::cin, str);
    if (str.empty())
        empty_error();
    setLastName(str);

    std::cout << "nick name     : ";
    std::getline(std::cin, str);
    if (str.empty())
        empty_error();
    setNickName(str);

    std::cout << "phone number  : ";
    std::getline(std::cin, str);
    if (str.empty())
        empty_error();
    setPhoneNumber(str);

    std::cout << "darkest secret: ";
    std::getline(std::cin, str);
    if (str.empty())
        empty_error();
    setDarkestSecret(str);
}

//TODO:条件を満たす
void Contact::ft_view(void)
{
    int i;
    i = 0;
    std::string str;

    // 連絡先を全て表示
    std::cout << "====== INFO ======" << std::endl;

    str = getFirstName();
    if (10 < str.length())
        str = str.replace(10, str.length() - 10, "."); //文字列を置き換える
    std::cout << "firstname :" << str << std::endl;

    str = getLastName();
    if (10 < str.length())
        str = str.replace(10, str.length() - 10, ".");
    std::cout << "lastname :" << str << std::endl;

    str = getNickName();
    if (10 < str.length())
        str = str.replace(10, str.length() - 10, ".");
    std::cout << "nickname :" << str << std::endl;

    str = getPhoneNumber();
    if (10 < str.length())
        str = str.replace(10, str.length() - 10, ".");
    std::cout << "phone number :" << str << std::endl;

    str = getDarkestSecret();
    if (10 < str.length())
        str = str.replace(10, str.length() - 10, ".");
    std::cout << "darkest secret :" << str << std::endl;
}
