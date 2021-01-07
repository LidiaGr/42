//
// Created by Temple Tarsha on 1/7/21.
//

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::TargetGenerator(const TargetGenerator &) {}

TargetGenerator & TargetGenerator::operator=(const TargetGenerator &) {return *this;}

TargetGenerator::~TargetGenerator() {}

void TargetGenerator::learnTargetType(ATarget *target) {
	if (!target)
		return;
	std::vector<ATarget *>::iterator it = _targets.begin();
	std::vector<ATarget *>::iterator ite = _targets.end();
	for(; it != ite; it++) {
		if ((*it)->getType().compare(target->getType()) == 0) {
			return;
		}
	}
	_targets.push_back(target->clone());
}

void TargetGenerator::forgetTargetType(const std::string &targetName) {
	std::vector<ATarget *>::iterator it = _targets.begin();
	std::vector<ATarget *>::iterator ite = _targets.end();
	for(; it != ite; it++) {
		if ((*it)->getType().compare(targetName) == 0) {
			_targets.erase(it);
			return;
		}
	}
}

ATarget * TargetGenerator::createTarget(const std::string &name) {
	std::vector<ATarget *>::iterator it = _targets.begin();
	std::vector<ATarget *>::iterator ite = _targets.end();
	for (; it != ite; it++) {
		if ((*it)->getType().compare(name) == 0) {
			return ((*it)->clone());
		}
	}
	return (0);
}
