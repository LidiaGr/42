//
// Created by Temple Tarsha on 12/25/20.
//

#include "main.hpp"

void * serialize(void) {
	std::string str = "asdfghjklzxcvbnmwqertyu0123456789";
	char *data = new char[20];
	for (int i = 0; i < 8; i++) {
		data[i] = str[rand() % str.length()];
	}
	std::cout << data << std:: endl;
	int a = static_cast<int>(rand());
	std::cout << a << std::endl;
	*reinterpret_cast<int *>(data + 8) = a;
	for (int i = 12; i < 20; i++) {
		data[i] = str[rand() % str.length()];
		std::cout << data[i];
	}
	return static_cast<void *>(data);
}

Data * deserialize(void * raw) {
	Data *data = new Data;
	char *pre = static_cast<char *>(raw);
	std::string str = static_cast<std::string>(pre);
	data->s1 = str.substr(0, 8);
	data->s2 = str.substr(12, 8);
	data->n = *reinterpret_cast<int *>(pre + 8);
	return data;
}

int		main() {
	srand(time(nullptr));
	void *data = serialize();
	Data *res = deserialize(data);
	std::cout << std::endl << "____________________" << std::endl;
	std::cout << "s1: " << res->s1 << std::endl;
	std::cout << "n: " << res->n << std::endl;
	std::cout << "s2: " << res->s2 << std::endl;
	return 0;
}

