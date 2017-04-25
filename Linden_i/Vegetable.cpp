#include "Vegetable.hpp"

const std::string Vegetable::type = "vegetable";


void Vegetable::display() {
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

	std::cout << "You should thinning the ranges of " << name << " during";
	sortedDisplay(thinning);
	std::cout << std::endl;

	std::cout << "After thinning, the " << name << " should respect a distance of " << distance << "cm between each other." << std::endl;

	std::cout << "The " << name << " is ";
	if (mildew == true) {
		std::cout << "likely";
	}
	else if (mildew == false) {
		std::cout << "not likely";
	}
	std::cout << " to suffer from mildew." << std::endl;


	std::cout << "The " << name << " is ";
	if (powderyMildew == true) {
		std::cout << "likely";
	}
	else if (powderyMildew == false) {
		std::cout << "not likely";
	}
	std::cout << " to suffer from powdery mildew." << std::endl;
}

std::string Vegetable::getType(const Plant& p) {
	return type;
}
float Vegetable::getDistance(const Vegetable & v)
{
	return v.distance;
}

bool Vegetable::getMildew(const Vegetable & v)
{
	return v.mildew;
}

bool Vegetable::getPowderyMildew(const Vegetable & v)
{
	return v.powderyMildew;
}

bool Vegetable::getThinning(std::map<std::string, bool>::iterator it)
{
	return (*it).second;
}

void Vegetable::setDistance(Vegetable & v, float d)
{
	v.distance = d;
}

void Vegetable::setMildew(Vegetable & v, bool m)
{
	v.mildew = m;
}

void Vegetable::setPowderyMildew(Vegetable & v, bool pm)
{
	v.powderyMildew = pm;
}

void Vegetable::setThinning(std::string s, bool b)
{
	thinning[s] = b;
}
