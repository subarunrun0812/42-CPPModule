#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

// uintptr_t
#include <cstdint>
#include <iostream>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define NORMAL "\x1b[0m"
#define LINE "=========="

typedef struct s_Data
{
	std::string name;
	int		birthday;
}	Data;

class Serializer
{
private:
	Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif