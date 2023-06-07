#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>

// 電話帳のクラス
class PhoneBook
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
    public: //公開メンバ
        PhoneBook(); //コンストラクタ関数
        // getter
        std::string getFirstName(void) const;
        std::string getLastName(void) const;
        std::string getNickName(void) const;
        std::string getPhoneNumber(void) const;
        std::string getDarkestSecret(void) const;

       // privateアクセスのメンバ変数を読み書きしたいため、getter,setter関数を用意する

       //setter
        void setFirstName(std::string str);
        void setLastName(std::string str);
        void setNickName(std::string str);
        void setPhoneNumber(std::string str);
        void setDarkestSecret(std::string str);
        void ft_search(void);
        void ft_add(void);
        void empty_error(void);

};

// 連絡先のクラス



#endif