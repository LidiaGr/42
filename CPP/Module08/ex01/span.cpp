//
// Created by Temple Tarsha on 12/29/20.
//

#include "span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _arr(), _size(N) {}

Span::~Span() {
	_arr.erase(_arr.begin(), _arr.end());
}

Span::Span(const Span &src) {
	*this = src;
}

Span & Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		this->_arr = rhs._arr;
		this->_size = rhs._size;
	}
	return *this;
}

void Span::addNumber(int nb) {
	if (_arr.size() != _size) {
		_arr.push_back(nb);
	}
	else
		throw std::out_of_range("Element is out of range");
}

int Span::shortestSpan() {
	if (_arr.empty() || _arr.size() == 1)
		throw std::length_error("Array is empty or have not enough elements for shortestSpan");

	_min = min_element(_arr.begin(), _arr.end());
	_short = _arr.begin();

	for (std::vector<int>::iterator it = _arr.begin(); it != _arr.end() - 1; ++it) {
		if (it == _min)
			continue;
		std::vector<int>::iterator num = min(it, it + 1);
		if (num < _short)
			_short = num;
	}
	return *_short - *_min;
}

int Span::longestSpan() {
	if (_arr.empty() || _arr.size() == 1)
		throw std::length_error("Array is empty or have not enough elements for longestSpan");

	_min = min_element(_arr.begin(), _arr.end());
	_max = max_element(_arr.begin(), _arr.end());

	return *_max - *_min;
}

void Span::setArr(std::vector<int> & vec) {
	_arr = vec;
}

unsigned int Span::getSize() {
	return _size;
}