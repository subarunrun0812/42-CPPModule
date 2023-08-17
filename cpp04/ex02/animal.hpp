#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

// 純粋仮想関数が一つでもあれば、そのクラスは抽象クラスになる
class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(const Animal &animal);
	Animal &operator=(const Animal &animal);
	// virtual = 仮想関数
	virtual ~Animal();
	virtual void makeSound() const = 0; // 純粋仮想関数
	std::string getType() const;
};

#endif
