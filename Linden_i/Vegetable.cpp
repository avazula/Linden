#include "Vegetable.hpp"

//Type of the derived plant
const std::string Vegetable::type = "vegetable";

//Method for creating new objects of the class (please refer to the Factory cpp files)
Plant * Vegetable::Create(std::string n, std::vector<bool> in, std::vector<bool> out, std::vector<bool> harv, float d, bool m, bool pm)
{
	return new Vegetable(n,in,out,harv,d,m,pm);
}

//Definition of the display() function that was pure virtual in the Plant class
void Vegetable::display() {
	std::cout << "Name of the plant: " << name << std::endl;
	std::cout << "This plant is of type: " << type << std::endl;
	//Displaying of data about sowing and harvesting
	std::cout << name << " is likely to be sowed indoors in";
	sortedDisplay(indoors);
	std::cout << std::endl;

	std::cout << name << " is likely to be sowed outdoors in";
	sortedDisplay(outdoors);
	std::cout << std::endl;

	std::cout << "You should harvest " << name << " in";
	sortedDisplay(harvest);
	std::cout << std::endl;
	//Displaying of the distance that needs to be respected between two vegetables of this species for the biggest crop yield
	std::cout << "After thinning, the " << name << " should respect a distance of " << distance << "cm between each other." << std::endl;

	//Saying if the vegetable is likely to suffer from (powdery) mildew
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

//Accessors
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

//Accessors
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
