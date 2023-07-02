#include "phonebook.hpp"

//クラスの初期化にデフォルトコンストラクタを使用
//少なくとも、コンストラクタを1つ定義する必要がある。
Contact::Contact()
{
}

// constをつけることでオブジェクトの状態を変化しない事を明示的に示す
std::string Contact::getFirstName(void) const
{
    return (this->firstName);
}

std::string Contact::getLastName(void) const
{
    return (this->lastName);
}

std::string Contact::getNickName(void) const
{
    return (this->nickname);
}

std::string Contact::getPhoneNumber(void) const
{
    return (this->phoneNumber);
}

std::string Contact::getDarkestSecret(void) const
{
    //return (this->darkestSecret);
    return (this->darkestSecret);
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
    if (!std::getline(std::cin, str)) 
	{
    	// Ctrl-D が押された、あるいは他の入力エラーが発生した
 		std::cin.clear(); // エラー状態をリセット
    	exit;
    }
    if (str.empty())
        return (empty_error());
    setFirstName(str);

    std::cout << "last name     : ";
    std::getline(std::cin, str);
    if (str.empty())
        std::cin.clear();
    setLastName(str);

    std::cout << "nick name     : ";
    std::getline(std::cin, str);
    if (str.empty())
        std::cin.clear();
    setNickName(str);

    std::cout << "phone number  : ";
    std::getline(std::cin, str);
    if (str.empty())
        std::cin.clear();
    setPhoneNumber(str);

    std::cout << "darkest secret: ";
    std::getline(std::cin, str);
    if (str.empty())
        std::cin.clear();
    setDarkestSecret(str);
}

// strの長さが10より長い場合は、10文字目以降を"."で置き換える。
// 10文字未満の場合は空白で埋める。
std::string Contact::formatString(std::string str)
{
    std::string res;
    // std::cout << "strの長さは" << str.length() << std::endl;
    if (10 < str.length())
    {
        str = str.replace(9, str.length() - 10, ".");//文字列を置き換える
        for (int i = 0; i < 10; i++)
        {
            res += str[i];
            // std::cout << "res[" << i << "]=" << res[i] << std::endl;
        }
    }
    else
        res = str;
    return res;
}

// 文字列を|で囲って表示する。
void Contact::printColumn(std::string str)
{
    std::cout << "|";
    int space_len = 10 - str.length();
    // std::cout << "str = \"" << str << "\""<< std::endl;
    // std::cout << "space_lenの長さは" << space_len << std::endl;
    for (int i = 0; i < space_len ; i++)
    {
        // std::cout << "iの長さは" << i << std::endl;
        std::cout << " ";
    }
    std::cout << str;
    std::cout << "|" << std::endl;
}

// これらの関数をft_view内で呼び出す。
void Contact::ft_view(void)
{
    // 連絡先を全て表示
    std::cout << "========= INFO ===========" << std::endl;

    std::cout << "firstname     ";
    printColumn(formatString(getFirstName()));

    std::cout << "lastname      ";
    printColumn(formatString(getLastName()));

    std::cout << "nickname      ";
    printColumn(formatString(getNickName()));

    std::cout << "phone number  ";
    printColumn(formatString(getPhoneNumber()));

    std::cout << "darkest secret";
    printColumn(formatString(getDarkestSecret()));
}
