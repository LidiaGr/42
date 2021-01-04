//
// Created by Temple Tarsha on 12/29/20.
//

#include "mutantstack.hpp"
#include <iostream>

int main()
{
	std::cout << "____________TEST STANDARD__________" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element: " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "Stack size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737); //[...] mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << "Element: " << *it << std::endl;
		++it; }

	std::cout << std::endl << "________TEST COPY CONSTRUCTOR_______" << std::endl;
	std::stack<int> s(mstack);
	while (!s.empty()) {
		std::cout << s.top() << std::endl;
		s.pop();
	}
	if (s.empty())
		std::cout << "Stack is empty" << std::endl;

	std::cout << std::endl << "________TEST POSTFIX INC/DEC________" << std::endl;
	MutantStack<int> st(mstack);
	MutantStack<int>::iterator i = st.begin();

	std::cout << "Begin: " << *i << std::endl;
	i++;
	std::cout << "Next: " << *i << std::endl;
	i++;
	std::cout << "Next: " << *i << std::endl;
	i--;
	std::cout << "Previous: " << *i << std::endl;

	return 0;
}