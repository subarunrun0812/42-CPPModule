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
        std::string getter_firstName(void);
       // privateアクセスのメンバ変数を読み書きしたいため、getter,setter関数を用意する

};

// 連絡先のクラス

#endif