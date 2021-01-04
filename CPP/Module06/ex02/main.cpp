//
// Created by Temple Tarsha on 12/25/20.
//

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	Base *base;
	int n = rand() % 3;

	switch (n) {
		case 0:
		base = new A();
		std::cout << "A class created." << std::endl;
		break;
		case 1:
		base = new B();
		std::cout << "B class created." << std::endl;
		break;
		case 2:
		base = new C();
		std::cout << "C class created." << std::endl;
		break;
	}
	return base;
}

void identify_from_pointer(Base * p) {
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		return;
}

void identify_from_reference(Base & p) {
	if (dynamic_cast<A *>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(&p))
		std::cout << "C" << std::endl;
	else
		return;
}

int main() {
	srand(time(nullptr));
	Base *base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);
}
