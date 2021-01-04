//
// Created by Temple Tarsha on 12/29/20.
//

#include "span.hpp"

int RandomNumber () { return (std::rand()%100); }

int main()
{
	std::cout << "____________________________________" << std::endl;
	std::cout << "______________STANDART______________" << std::endl;
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "____________________________________" << std::endl;
	std::cout << "_________ADD EXTRA ELEMENTS_________" << std::endl;
	try {
		sp.addNumber(11);
		sp.addNumber(111);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "____________________________________" << std::endl;
	std::cout << "______EXCEPTION ARRAY SIZE = 1______" << std::endl;
	try {
		Span sp1 = Span(1);
		sp1.addNumber(11);
		std::cout << sp1.shortestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "____________________________________" << std::endl;
	std::cout << "______EXCEPTION ARRAY SIZE = 0______" << std::endl;
	try {
		Span sp2 = Span(0);
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "____________________________________" << std::endl;
	std::cout << "_________10000 NUMBERS SPAN_________" << std::endl;
	std::srand(std::time(nullptr));

	Span sp3(10000);
	std::vector<int> v(10000);
	std::generate(v.begin(), v.end(), RandomNumber);
	sp3.setArr(v);
	std::cout << "Array size is " << sp3.getSize() << std::endl;
	std::cout << "Shortest span is " << sp3.shortestSpan() << std::endl;
	std::cout << "Longest span is " << sp3.longestSpan() << std::endl;
}
