//
// Created by Temple Tarsha on 1/7/21.
//

#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <vector>

class ATarget;

class TargetGenerator {

private:
	std::vector<ATarget *> _targets;
	TargetGenerator(TargetGenerator const &);
	TargetGenerator & operator=(TargetGenerator const &);

public:
	TargetGenerator();
	~TargetGenerator();

	void learnTargetType(ATarget* target);
	void forgetTargetType(std::string const & targetName);
	ATarget* createTarget(std::string const & name);
};

#endif //TARGETGENERATOR_HPP
