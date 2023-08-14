#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& Wronganimal);
	WrongAnimal& operator=(const WrongAnimal& Wronganimal);
	// 仮想関数
	virtual ~WrongAnimal();
	virtual void makeSound() const;
	std::string getType() const;
};

#endif