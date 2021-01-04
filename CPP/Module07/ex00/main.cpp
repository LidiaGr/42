//
// Created by Temple Tarsha on 12/27/20.
//

#include "whatever.hpp"

class
Awesome {
public:
	Awesome() {}
	Awesome( int n ) : _n( n ) {}
	int getN() {return this->_n;};
	Awesome & operator=(Awesome const & rhs) {
		this->_n = rhs._n;
		return *this;
	}
	bool operator==( Awesome const & rhs ) { return (this->_n == rhs._n); }
	bool operator!=( Awesome const & rhs ) { return (this->_n != rhs._n); }
	bool operator>( Awesome const & rhs ) { return (this->_n > rhs._n); }
	bool operator<( Awesome const & rhs ) { return (this->_n < rhs._n); }
	bool operator>=( Awesome const & rhs ) { return (this->_n >= rhs._n); }
	bool operator<=( Awesome const & rhs ) { return (this->_n <= rhs._n); }
private:
	int _n;
};

int main( void ) {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << "__________________" << std::endl;
	Awesome e(10);
	Awesome f(100);

	std::cout << "e = " << e.getN() << ", f = " << f.getN() << std::endl;
	::swap( e, f );
	std::cout << "e = " << e.getN() << ", f = " << f.getN() << std::endl;
	std::cout << "min( e, f ) = " << ::min( e.getN(), f.getN() ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e.getN(), f.getN() ) << std::endl;

	return 0;
}
