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
		//TODO: friendを削除
		//固定小数点数を浮動小数点数の形式で出力ストリームに挿入できるようにします
		//非メンバ関数として扱われるため、friend関数にする必要がある
		//最初の引数がstreamで、このメンバ関数が呼び出されるインスタンスがストリームに
		//なってしまい、意図した動作を達成できなくなるため。
		friend std::ostream &operator<<(std::ostream& os, const Fixed &fixed);

		//四則演算
		Fixed operator +(const Fixed& other) const;
		Fixed operator -(const Fixed& other) const;
		Fixed operator *(const Fixed& other) const;
		Fixed operator /(const Fixed& other) const;

		bool operator >(const Fixed& other) const;
		bool operator <(const Fixed& other) const;
		bool operator >=(const Fixed& other) const;
		bool operator <=(const Fixed& other) const;
		bool operator ==(const Fixed& other) const;
		bool operator !=(const Fixed& other) const;

		Fixed& operator ++ (); //pre-increment ++val
		Fixed operator ++ (int); //post-increment val++
		Fixed& operator -- ();
		Fixed operator -- (int);

		// staticで、クラスのオブジェクトを介して呼ばれるのではなく、
		// クラス自体に属する。
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);


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