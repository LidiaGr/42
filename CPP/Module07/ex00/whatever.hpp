//
// Created by Temple Tarsha on 12/27/20.
//

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <iomanip>

template<typename T>
T	max(T const & x, T const & y) {
	return ( (x>y) ? x : y ) ;
}

template<typename T>
T	min(T const & x, T const & y) {
	return ( (x<y) ? x : y ) ;
}

template<typename T>
void	swap(T & x, T & y ) {
	T tmp;
	tmp = x;
	x = y;
	y = tmp;
}

#endif
