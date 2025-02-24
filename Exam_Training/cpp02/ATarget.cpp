#include "ATarget.hpp"

ATarget::ATarget(const std::string &inputType) : type(inputType) {};
ATarget::~ATarget() {};

const std::string &ATarget::getType() const {
	return type;
};

void ATarget::getHitBySpell(const ASpell &spell) const {
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
};