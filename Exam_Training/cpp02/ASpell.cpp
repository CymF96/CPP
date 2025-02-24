#include "ASpell.hpp"

ASpell::ASpell(const std::string &inputName, const std::string &inputEffects) : name(inputName), effects(inputEffects) {};
ASpell::~ASpell() {};
const std::string &ASpell::getName() const {
	return name;
};
const std::string &ASpell::getEffects() const {
	return effects;
};

void ASpell::castSpell(const ATarget &target) const {
	target.getHitBySpell(*this);
};