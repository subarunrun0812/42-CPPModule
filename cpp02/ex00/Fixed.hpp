#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int fixedPointValue;
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed); //コピーコンストラクタ
		Fixed& operator=(const Fixed& fixed); //コピー代入演算子
		~Fixed();
		// 固定小数点の値を返す
		// constがメンバ関数の後ろについた場合、メンバ変数の値を変更しない[読み取り専用]という事を表している
		int getRawBits(void) const;
		// 固定小数点の値を設定する
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

#endif