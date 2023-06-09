#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#define MAX_SIZE 8

// 電話帳のクラス
class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
    public: //公開メンバ
        //Default constructor
        Contact();
        // privateアクセスのメンバ変数を読み書きしたいため、getter,setter関数を用意する
        // getter
        std::string getFirstName(void) const;
        std::string getLastName(void) const;
        std::string getNickName(void) const;
        std::string getPhoneNumber(void) const;
        std::string getDarkestSecret(void) const;
       //setter
        void setFirstName(std::string str);
        void setLastName(std::string str);
        void setNickName(std::string str);
        void setPhoneNumber(std::string str);
        void setDarkestSecret(std::string str);

        void ft_view(void);
        bool getInput(std::string& str);
        void ft_add(void);
        void empty_error(void);
        std::string formatString(std::string str);
        void printColumn(std::string str);
};

// 連絡先の配列にアクセスするクラス
class PhoneBook
{
    private:
        Contact contacts[MAX_SIZE];
    public:
        PhoneBook();
        void add_contact(void);
        void view_contact(void);
};

#endif