#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP
#include <iostream>
#include <string>
#include <vector>
#include "ASpell.hpp"

class SpellBook {
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *spell);
		void forgetSpell(const std::string &spell);
		ASpell *createSpell(const std::string &spell); 

	private:
		std::vector<ASpell *> spellBook;
		SpellBook(const SpellBook &other);
		SpellBook &operator=(const SpellBook &other);
};

#endif