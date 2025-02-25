#include "SpellBook.hpp"

SpellBook::SpellBook() {};
SpellBook::~SpellBook() {
	std::vector<ASpell *>::iterator it = spellBook.begin();
	for (; it != spellBook.end(); ++it) {
		delete *it;
	}
};

void SpellBook::learnSpell(ASpell *spell) {
	if (spell) {
		std::vector<ASpell *>::iterator it = spellBook.begin();
		for (; it != spellBook.end(); ++it) {
			if (*it == spell)
				return ;
		}
		spellBook.push_back(spell->clone());
	} else
	std::cout << "Error Spell nullptr\n";

};
void SpellBook::forgetSpell(const std::string &spell) {
	std::vector<ASpell *>::iterator it = spellBook.begin();
	for (; it != spellBook.end(); ++it) {
		if ((*it)->getName() == spell) {
			delete *it;
			spellBook.erase(it);
			return ;
		}
	}
	std::cout << "Spell not known anyway\n";
};
ASpell *SpellBook::createSpell(const std::string &spell) {
	std::vector<ASpell *>::iterator it = spellBook.begin();
	for (; it != spellBook.end(); ++it) {
		if ((*it)->getName() == spell) {
			return *it;
		}
	}
	return NULL;
};

SpellBook::SpellBook(const SpellBook &other) { (void)other; };
SpellBook &SpellBook::operator=(const SpellBook &other) { (void)other; return *this; };