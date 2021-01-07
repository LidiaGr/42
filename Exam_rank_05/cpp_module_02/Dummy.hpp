//
// Created by Temple Tarsha on 1/6/21.
//

#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "ATarget.hpp"

class Dummy : public ATarget {

public:
	Dummy();
	~Dummy();
	Dummy(Dummy const & src);
	Dummy & operator=(Dummy const & rhs);

	virtual ATarget * clone() const;
};


#endif //DUMMY_HPP
