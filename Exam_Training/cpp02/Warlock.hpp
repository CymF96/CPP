#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <iostream>
#include <string>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
	public:
		Warlock(const std::string &inputName, const std::string &inputTitle);
		~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTitle(const std::string &inputTitle);
		void introduce() const;
		void learnSpell(ASpell *spell);
		void forgetSpell(const std::string &spell);
		void launchSpell(const std::string &spell, const ATarget &target);

	private:
		Warlock(const Warlock &other);
		Warlock &operator=(const Warlock &other);
		std::string name;
		std::string title;
		std::vector<ASpell *> spellBook;
};
#endif