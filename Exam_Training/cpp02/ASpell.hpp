#ifndef ASPELL_HPP
#define ASPELL_HPP
#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell {
	public:
		ASpell(const std::string &inputName, const std::string &inputEffects);
		virtual ~ASpell();

		const std::string &getName() const;
		const std::string &getEffects() const;
		void castSpell(const ATarget &target) const;
		virtual ASpell *clone() const = 0;

	protected:
		std::string name;
		std::string effects;
};
#endif