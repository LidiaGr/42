//
// Created by Temple Tarsha on 12/27/20.
//

#include "iter.hpp"

void	plusOne(int const & a) {
	std::cout << "a = " << (a + 1) << std::endl;
}

void 	printStr(std::string const & a) {
	std::cout << "arr = " << a << std::endl;
}

void	printFloat(float const & f) {
	std::cout << "f = " << f << std::endl;
}

int 	main() {
	int a[] = {2, 4, 6, 8};
	::iter( a, 4, plusOne );

	std::cout << "__________________" << std::endl;
	std::string arr[] = {"hello", "world", "today"};
	::iter( arr, 3, printStr );

	std::cout << "__________________" << std::endl;
	float f[] = {2.1f, 4.2f, 0.1f};
	::iter( f, 3, printFloat );
}


//class Awesome
//{
//public:
//	Awesome( void ) : _n( 42 ) { return; }
//	int get( void ) const { return this->_n; }
//private:
//	int _n;
//};
//std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
//
//template< typename T >
//void print( T const & x ) { std::cout << x << std::endl; return; }
//
//int main() {
//	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
//	Awesome tab2[5];
//
//	iter( tab, 5, print );
//	iter( tab2, 5, print );
//
//	return 0;
//}
