#include "Warlock.hpp"

Warlock::Warlock(const std::string &inputName, const std::string &inputTitle) : name(inputName), title(inputTitle) {
	std::cout << name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock() {
	std::cout << name << ": My job here is done!" << std::endl;
};
const std::string &Warlock::getName() const{
	return name;
};
const std::string &Warlock::getTitle() const{
	return title;
}
void Warlock::setTitle(const std::string &inputTitle) {
	title = inputTitle;
};
void Warlock::introduce() const {
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}
Warlock::Warlock(const Warlock &other) { (void)other; };
Warlock &Warlock::operator=(const Warlock &other) { (void)other; return *this; };