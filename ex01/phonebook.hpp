#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>

void ft_search(void);
void ft_add(void);
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
       // privateアクセスのメンバ変数を読み書きしたいため、getter,setter関数を用意する

       //setter
        void setFirstName(std::string str);

};

// 連絡先のクラス



#endif