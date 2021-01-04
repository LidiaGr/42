//
// Created by Temple Tarsha on 12/29/20.
//

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T> {

public:
	MutantStack() : std::stack<T>() {};
	virtual ~MutantStack() {};

	MutantStack(MutantStack const & src) : std::stack<T>(src) { *this = src; };
	MutantStack & operator=(MutantStack const &) { return *this; };


	class iterator : public std::bidirectional_iterator_tag {
	private:
		T *_data;

	public:
		iterator() : _data(0) {};
		iterator(T *data) : _data(data) {}
		~iterator() {}
		iterator(iterator const & src) { *this = src; }
		iterator & operator=(iterator const & rhs) { _data = rhs._data; return *this; }

		bool operator==(const iterator& rhs) const {return _data == rhs._data;}
		bool operator!=(const iterator& rhs) const {return _data != rhs._data;}
		int& operator*() {return *_data;}
		T* operator->() const {return &(operator*());}

		iterator& operator++() { --_data; return *this; }
		iterator operator++(int) { iterator tmp(*this); operator++(); return tmp; }

		iterator& operator--() { ++_data; return *this; }
		iterator operator--(int) { iterator tmp(*this); operator--(); return tmp; }
	};


	iterator begin() {
		return iterator(&(this->top()));
	}

	iterator end() {
		return iterator(&(this->top()) - this->size());
	}

};


#endif //MUTANTSTACK_HPP
