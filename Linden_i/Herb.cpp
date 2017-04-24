#include "Herb.hpp"

const std::string Herb::type = "herb";

void Herb::display() {

	std::cout << "Name of the plant: " << name << std::endl;
	std::cout << "This plant is of type: " << type << std::endl;

	/*Some herbs do not need to be sowed indoors, hence the creation of
	a variable cond that checks in there is any month for which it is
	good to sow this herb indoors.*/
	int cond = 0;
	for (std::map<std::string, bool>::iterator it = indoors.begin(); it != indoors.end(); ++it) {
		if ((*it).second == true) cond++;
	}

	/*If the herb is indeed likely to be sowed indoors,
	then display these months.*/
	if (cond != 0) {
		std::cout << name << " should rather be sowed indoors in ";
		for (std::map<std::string, bool>::iterator it = indoors.begin(); it != indoors.end(); ++it) {
			if ((*it).second == true) std::cout << (*it).first << " ";
		}
		std::cout << "." << std::endl;
	}

	std::cout << name << " is likely to be sowed outdoors in ";
	for (std::map<std::string, bool>::iterator it = outdoors.begin(); it != outdoors.end(); ++it) {
		if ((*it).second == true) std::cout << (*it).first << " ";
	}
	std::cout << std::endl;

	std::cout << "You should harvest " << name << " in ";
	for (std::map<std::string, bool>::iterator it = harvest.begin(); it != harvest.end(); ++it) {
		if ((*it).second) std::cout << (*it).first << " ";
	}
	std::cout << "." << std::endl;

	if (perrenial == true) {
		std::cout << "The " << name << " is perrenial." << std::endl;
	}
	else {
		std::cout << "The " << name << " is an annual plant." << std::endl;
	}
}
std::string Herb::getType() {
	return type;
}

bool Herb::getPerrenial(const Herb& h) {
	return perrenial;
}

void Herb::setPerrenial(bool b) {
	perrenial = b;
}