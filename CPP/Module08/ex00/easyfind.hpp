//
// Created by Temple Tarsha on 12/28/20.
//

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

template<typename T>
typename T::const_iterator	easyfind(T const & arr, int const & id) {
	typename T::const_iterator it;

	it = std::find(arr.begin(), arr.end(), id);
	if (it != arr.end()) {
		std::cout << "Element found in array. Index: " << *it << std::endl;
		return it;
	} else {
		throw std::invalid_argument("No such element in the array");
	}
}

#endif //EASYFIND_HPP
