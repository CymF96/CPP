#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {};
TargetGenerator::~TargetGenerator() {
	std::vector<ATarget *>::iterator it = targetList.begin();
	for (; it != targetList.end(); ++it) {
		delete *it;
	}
};

void TargetGenerator::learnTargetType(ATarget *target) {
	std::vector<ATarget *>::iterator it = targetList.begin();
	for (; it != targetList.end(); ++it) {
		if (*it == target)
			return ;
	}
	targetList.push_back(target->clone());
};
void TargetGenerator::forgetTargetType(const std::string &type) {
	std::vector<ATarget *>::iterator it = targetList.begin();
	for (; it != targetList.end(); ++it) {
		if ((*it)->getType() == type) {
			delete *it;
			targetList.erase(it);
			return ;
		}
	}	
};
ATarget *TargetGenerator::createTarget(const std::string &type) {
	std::vector<ATarget *>::iterator it = targetList.begin();
	for (; it != targetList.end(); ++it) {
		if ((*it)->getType() == type) {
			return *it;
		}
	}
	return NULL;
};

TargetGenerator::TargetGenerator(const TargetGenerator &other) { (void)other; };
TargetGenerator &TargetGenerator::operator=(const TargetGenerator &other) { (void)other; return *this; };