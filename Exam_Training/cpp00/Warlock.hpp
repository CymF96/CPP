#pragma once
#include <iostream>
#include <string>

class Warlock {
	public:
		Warlock(const std::string &inputName, const std::string &inputTitle);
		~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTitle(const std::string &inputTitle);
		void introduce() const;

	private:
		Warlock(const Warlock &other);
		Warlock &operator=(const Warlock &other);
		std::string name;
		std::string title;

};