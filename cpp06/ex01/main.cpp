#include "Serializer.hpp"

Data* NormalTest_1()
{
	std::cout << LINE " NormalTest_1 " LINE << std::endl;
	Data* data = new Data;

	data->name = "sasaki";
	data->birthday = 2004;

	uintptr_t raw = Serializer::serialize(data);
	Data* data_ptr = Serializer::deserialize(raw);
	std::cout << "ポインタを符号無し整数型に変換=>" << std::endl;
	std::cout << GREEN "raw: " << raw << NORMAL << std::endl;
	std::cout << "元のDATA型に戻す=>" << std::endl;
	std::cout << GREEN"data_ptr->name = " << data_ptr->name << std::endl;
	std::cout << "data_ptr->birthday " << data_ptr->birthday << NORMAL << std::endl;

	return (data);
}

Data* NormalTest_2()
{
	std::cout << LINE " NormalTest_2 " LINE << std::endl;
	Data* data = new Data;

	data->name = "subaru";
	data->birthday = 812;

	uintptr_t raw = Serializer::serialize(data);
	Data* data_ptr = Serializer::deserialize(raw);
	std::cout << "ポインタを符号無し整数型に変換=>" << std::endl;
	std::cout << GREEN "raw: " << raw << NORMAL << std::endl;
	std::cout << "元のDATA型に戻す=>" << std::endl;
	std::cout << GREEN "data_ptr->name = " << data_ptr->name << std::endl;
	std::cout << "data_ptr->birthday " << data_ptr->birthday << NORMAL << std::endl;

	return (data);
}

int main(void)
{
	Data* data1 = NormalTest_1();
	Data* data2 = NormalTest_2();
	delete data1;
	delete data2;
	return EXIT_SUCCESS;
}