#include "Legume.hpp"

const std::string Legume::type = "legume";

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
	
	std::cout << "The " << name << " is ";
	if (mildew == true) {
		std::cout << "likely";
	}
	else if (mildew == false) {
		std::cout << "not likely";
	}
	std::cout << " to suffer from mildew." << std::endl;

}

std::string Legume::getType()
{
	return type;
}

bool Legume::getMildew(const Legume & l)
{
	return l.mildew;
}

void Legume::setMildew(Legume & l, bool m)
{
	l.mildew = m;
}
