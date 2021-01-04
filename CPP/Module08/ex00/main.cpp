//
// Created by Temple Tarsha on 12/28/20.
//

#include "easyfind.hpp"
#include <vector>
#include <set>
#include <list>

int		main() {
	std::cout << "VECTOR_________________" << std::endl;
	std::vector<int> v;
	int id = 5;

	for (int i = 0; i < 20; i++) {
		v.push_back(i);
	}
	try {
		easyfind(v, id);
		id = 100000;
		easyfind(v, id);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "SET____________________" << std::endl;
	std::set<int> s;

	for (int i = 0; i < 10; i++) {
		s.insert(i);
	}
	std::cout << "Array size: " << s.size() << std::endl;
	std::cout << "Elements in a row: ";
	for (int i = 0; i < 10; i++)
		std::cout << *s.find(i) << " ";
	std::cout << std::endl;
	for (int i = 8; i < 11; i++) {
		try {
			easyfind(s, i);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "LIST___________________" << std::endl;
	std::list<int> l(20);
	id = 16;

	for (int i = 0; i < 20; i++) {
		l.push_back(i);
	}
	std::cout << "last: " << l.back() << std::endl;

	try {
		easyfind(l, id);
		id = 20;
		easyfind(l, id);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
