//
// Created by Lidia Grigoreva on 08/01/2021.
//

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock {
private:
	std::string _name;
	std::string _title;
	Warlock() {};
	Warlock(Warlock const &) {};
	Warlock & operator=(Warlock const &) {return *this;};


public:
	Warlock(std::string name, std::string title);
	~Warlock();

	std::string const & getName() const;
	std::string const & getTitle() const;
	void setTitle(std::string const & title);

	void introduce() const;
};


#endif //WARLOCK_HPP
