//
// Created by Lidia Grigoreva on 08/01/2021.
//

#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <vector>

class TargetGenerator {
private:
	std::vector<ATarget *> _targets;
	TargetGenerator(TargetGenerator const &) {};
	TargetGenerator & operator=(TargetGenerator const &) {return *this;}

public:
	TargetGenerator();
	virtual ~TargetGenerator();

	void learnTargetType(ATarget * target);
	void forgetTargetType(std::string const & target);
	ATarget* createTarget(std::string const & target);
};


#endif //TARGETGENERATOR_HPP
