//
// Created by Temple Tarsha on 1/4/21.
//

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock {

private:
	std::string _name;
	std::string _title;
	Warlock() {};
	Warlock( const Warlock & ) {};
	Warlock & operator=( const Warlock & ) {return *this;};

public:
	~Warlock();
	Warlock(std::string name, std::string title);

	std::string getName() const;
	std::string getTitle() const;
	void setTitle(std::string info);

	void introduce() const;
};

#endif //WARLOCK_HPP
