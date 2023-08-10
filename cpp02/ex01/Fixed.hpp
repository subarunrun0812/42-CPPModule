#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <math.h>

class Fixed
{
	private:
		int fixedPointValue;//固定小数点数
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed); //コピーコンストラクタ
		Fixed& operator=(const Fixed& fixed); //コピー代入演算子
		~Fixed();
		//整数を受け取るコンストラクタ
		Fixed(const int int_val);
		//浮動小数点を受け取るコンストラクタ
		Fixed(const float float_val);
		//TODO: frind関数を使わずに実装する。<<演算子のオーバーロードは
		//クラスの外で定義する。Fixedクラスのメンバ関数を使って、非メンバの
		//オーバーロード関数を実装する
		friend std::ostream &operator<<(std::ostream& os, const Fixed &fixed);

		// 固定小数点の値を返す
		// constがメンバ関数の後ろについた場合、メンバ変数の値を変更しない[読み取り専用]という事を表している
		int getValue(void) const;
		// 固定小数点の値を設定する
		void setValue(int const value);
		//固定小数点を浮動小数点値に変換する
		float toFloat(void) const;
		// 固定小数点値を整数値に変換する
		int toInt(void) const;

};

#endif