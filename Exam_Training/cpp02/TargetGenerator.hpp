#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP
#include <iostream>
#include <string>
#include <vector>
#include "ATarget.hpp"

class TargetGenerator {
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *target);
		void forgetTargetType(const std::string &type);
		ATarget *createTarget(const std::string &type);

	private:
		std::vector<ATarget*> targetList;
		TargetGenerator(const TargetGenerator &other);
		TargetGenerator &operator=(const TargetGenerator &other);
};

#endif