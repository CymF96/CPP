#ifndef ATARGET_HPP
#define ATARGET_HPP
#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget {
	public:
		ATarget(const std::string &inputType);
		virtual ~ATarget();

		const std::string &getType() const;
		void getHitBySpell(const ASpell &spell) const;
		virtual ATarget *clone() const = 0;

	protected:
		std::string type;
};
#endif