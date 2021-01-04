//
// Created by Temple Tarsha on 12/27/20.
//

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<class T>
class Array {

private:
	T *_data;
	unsigned int _size;

public:
	Array() {
		_data = new T[0];
		_size = 0;
	}

	Array(unsigned int n) {
		_data = new T[n];
		_size = n;
	}

	~Array() {
		delete [] _data;
	}

	Array(const Array & src) {
		*this = src;
	}

	Array & operator=(const Array & rhs) {
		if (this != &rhs) {
			_data = new T[rhs._size];
			for (unsigned int i = 0; i < rhs._size; ++i) {
				this->_data[i] = rhs._data[i];
			}
			this->_size = rhs._size;
		}
		return *this;
	}

	T& operator[](unsigned int index) {
		if (_size == 0 || index < 0 || index >= _size)
			throw (std::out_of_range("Error: index is out of range"));
		return _data[index];
	}

	unsigned int	size();
};

template <typename T>
unsigned int Array<T>::size() { return _size; }

#endif //ARRAY_HPP
