#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "BrickWall.hpp"
#include "Polymorph.hpp"
#include "Fireball.hpp"
#include "TargetGenerator.hpp"

int main(void)
{
	std::cout << "--- Constructors:\n";
	Warlock richard("Richard", "The Great");

	std::cout << "--- Spells:\n";
	Polymorph *critter = new Polymorph();
	Fireball *fire = new Fireball();
	Fwoosh *boom = new Fwoosh();
  Fwoosh *empty = nullptr;
  richard.learnSpell(empty);
	richard.learnSpell(critter);
	richard.learnSpell(fire);
	richard.forgetSpell("Fwoosh");
	richard.learnSpell(boom);
	richard.forgetSpell("Fwoosh");
	richard.forgetSpell("Fwoosh");
	richard.learnSpell(boom);
  richard.forgetSpell("");

	std::cout << "--- Targets:\n";
	Dummy *dummy = new Dummy();
	BrickWall *brick = new BrickWall();
  Dummy *emptyT = nullptr;

	TargetGenerator tarGen;
  tarGen.learnTargetType(emptyT);
	tarGen.learnTargetType(dummy);
	tarGen.learnTargetType(brick);
  tarGen.forgetTargetType("Target Practice Dummy");
  tarGen.learnTargetType(dummy);
  tarGen.forgetTargetType("Practice Dummy"); 
  tarGen.forgetTargetType(""); 


	std::cout << "--- Spells (all):\n";

	richard.launchSpell("Fwoosh", *tarGen.createTarget("Target Practice Dummy"));
	richard.launchSpell("Fireball", *tarGen.createTarget("Inconspicuous Red-brick Wall"));
	richard.launchSpell("Polymorph", *tarGen.createTarget("Practice Dummy"));

	std::cout << "--- Forgotten \"Fwoosh\":\n";

	richard.forgetSpell("Fwoosh");
	richard.launchSpell("Fwoosh", *tarGen.createTarget("Target Practice Dummy"));
	richard.launchSpell("Fireball", *tarGen.createTarget("Inconspicuous Red-brick Wall"));
	richard.launchSpell("Polymorph", *tarGen.createTarget("Target Practice Dummy"));

	std::cout << "--- Spells (all):\n";

	richard.learnSpell(boom);
	richard.launchSpell("Fwoosh", *tarGen.createTarget("Target Practice Dummy"));
	richard.launchSpell("Fireball", *tarGen.createTarget("Inconspicuous Red-brick Wall"));
	richard.launchSpell("Polymorph", *tarGen.createTarget("Target Practice Dummy"));

	std::cout << "--- Non-existant spell:\n";

	richard.launchSpell("ACID", *tarGen.createTarget("Inconspicuous Red-brick Wall"));
	richard.forgetSpell("ACID");
	richard.launchSpell("ACID", *tarGen.createTarget("Target Practice Dummy"));

	std::cout << "--- Destructors:\n";

  delete brick;
  delete dummy;
  delete boom;
  delete fire;
  delete critter;
	return (0);
}
