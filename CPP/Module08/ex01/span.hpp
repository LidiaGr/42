//
// Created by Temple Tarsha on 12/29/20.
//

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

#include <ctime>
#include <cstdlib>

class Span {

private:
	std::vector<int>	_arr;
	unsigned int		_size;
	std::vector<int>::iterator 	_min;
	std::vector<int>::iterator 	_short;
	std::vector<int>::iterator 	_max;
	Span();

public:
	Span(unsigned int N);
	~Span();

	Span(const Span & src);
	Span & operator=(const Span & rhs);

	void addNumber(int nb);
	int shortestSpan();
	int longestSpan();

	void setArr(std::vector<int> & vec);
	unsigned int getSize();
};


#endif //SPAN_HPP
