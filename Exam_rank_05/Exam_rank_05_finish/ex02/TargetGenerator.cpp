//
// Created by Lidia Grigoreva on 08/01/2021.
//

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() : _targets() {}

TargetGenerator::~TargetGenerator() {
	std::vector<ATarget*>::iterator it = _targets.begin();
	std::vector<ATarget*>::iterator ite = _targets.end();
	while(it != ite){
		delete *it;
		it++;
	}
	_targets.clear();
}

void TargetGenerator::learnTargetType(ATarget *target) {
	if (!target)
		return;
	std::vector<ATarget*>::iterator it = _targets.begin();
	std::vector<ATarget*>::iterator ite = _targets.end();
	while(it != ite){
		if((*it) == target)
			return;
		it++;
	}
	_targets.push_back(target->clone());
}

void TargetGenerator::forgetTargetType(const std::string &target) {
	std::vector<ATarget*>::iterator it = _targets.begin();
	std::vector<ATarget*>::iterator ite = _targets.end();
	while(it != ite){
		if((*it)->getType() == target) {
			delete *it;
			_targets.erase(it);
			return;
		}
		it++;
	}
}

ATarget * TargetGenerator::createTarget(const std::string &target) {
	std::vector<ATarget*>::iterator it = _targets.begin();
	std::vector<ATarget*>::iterator ite = _targets.end();
	while(it != ite){
		if((*it)->getType() == target) {
			return *it;
		}
		it++;
	}
	return 0;
}