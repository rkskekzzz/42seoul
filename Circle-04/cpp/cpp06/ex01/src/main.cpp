#include <iostream>
#include "Data.hpp"

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

int main() {
	Data data;

	data.val_1 = 'a';
	data.val_2 = 0;

	uintptr_t ptr_uint = serialize(&data);
	Data* ptr_data = deserialize(ptr_uint);

	std::cout << "< Print Pointer > " << std::endl;
	std::cout << "ptr_uint : " << ptr_uint << std::endl;
	std::cout << "ptr_uint(hex) : " << std::hex << ptr_uint << std::endl;
	std::cout << "ptr_data : " << ptr_data << std::endl;

	std::cout << "< Print Value > " << std::endl;
	std::cout << "val_1 : " << ptr_data->val_1 << std::endl;
	std::cout << "val_2 : " << ptr_data->val_2 << std::endl;
}
