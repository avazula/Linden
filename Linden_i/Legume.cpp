#include "Legume.hpp"

//Initializing the type of the derived plant
const std::string Legume::type = "legume";

//Method for creating new objects of the class (please refer to the Factory cpp files)
Plant * Legume::Create(std::string n, std::vector<bool> in, std::vector<bool> out, std::vector<bool> harv, bool m)
{
	return new Legume(n,in,out,harv,m);
}

//display() function that was pure virtual in the Plant class
void Legume::display() {
	std::cout << "Name of the plant: " << name << std::endl;
	std::cout << "This plant is of type: " << type << std::endl;

	std::cout << name << " is likely to be sowed indoors in";
	sortedDisplay(indoors);
	std::cout << std::endl;

	std::cout << name << " is likely to be sowed outdoors in";
	sortedDisplay(outdoors);
	std::cout << std::endl;

	std::cout << "You should harvest " << name << " in";
	sortedDisplay(harvest);
	std::cout << std::endl;
	
	//Checks whether the selected legume is likely to suffer from mildew
	std::cout << "The " << name << " is ";
	if (mildew == true) {
		std::cout << "likely";
	}
	else if (mildew == false) {
		std::cout << "not likely";
	}
	std::cout << " to suffer from mildew." << std::endl;

}

//Accessors
std::string Legume::getType(const Plant& p)
{
	return type;
}

bool Legume::getMildew(const Legume & l)
{
	return l.mildew;
}

//Mutators
void Legume::setMildew(Legume & l, bool m)
{
	l.mildew = m;
}
