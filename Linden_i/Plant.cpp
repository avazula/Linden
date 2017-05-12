#include "Plant.hpp"

//Function for initializing the vectors filled with false value for the default parameters of the constructor
std::vector<bool> Plant::getEmptyArray() {

	//Declaring and initializing a vector of booleans with false values for the default constructor
	std::vector<bool> vec = { false,false,false,false,false,false,false,false,false,false,false,false };

	return vec;
}

/*This function modifies the default behaviour of maps for displaying. Normally the displaying is ordered regarding to
the complexity. sortedDisplay() allows the elements of the map to be displayed in the order in which they have been
inserted. It will be used for the display() methods in the derived classes.*/
void Plant::sortedDisplay(std::map<std::string, bool> m) {
	for (int i = 0; i < nbMonths; i++) {
		if (m[calendar[i]] == true) std::cout << " " << calendar[i];
	}
}

//Check whether the selected month is good for sowing or harvesting
bool Plant::isOkIndoors(std::string s) {

	std::map<std::string, bool>::iterator it;
	it = indoors.find(s);
	//If the entered string does not match any month defined in the calendar array of the Plant.hpp file
	if (it == indoors.end()) return NULL;
	else return (*it).second;
}

bool Plant::isOkOutdoors(std::string s) {

	std::map<std::string, bool>::iterator it;
	it = outdoors.find(s);
	if (it == outdoors.end()) return NULL;
	else return (*it).second;
}

bool Plant::isOkHarvest(std::string s) {

	std::map<std::string, bool>::iterator it;
	it = harvest.find(s);
	if (it == harvest.end()) return NULL;
	else return (*it).second;
}

//Accessors
std::string Plant::getName(const Plant& p) {
	return name;
}

bool Plant::getIndoors(std::string month) {
	return indoors[month];
}

bool Plant::getOutdoors(std::string month) {
	return outdoors[month];
}

bool Plant::getHarvest(std::string month) {
	return harvest[month];
}

//Mutators
void Plant::setName(std::string newName) {
	name = newName;
}

void Plant::setIndoors(std::string s, bool b) {
	std::map<std::string, bool>::iterator it;
	it = indoors.find(s);
	if (it == indoors.end()) {
		std::cerr << "Bad writing of the month you are looking for. Please write the full name of the month and begin with an uppercase." << std::endl;
	}
	else it->second = b;
}

void Plant::setOutdoors(std::string s, bool b) {
	std::map<std::string, bool>::iterator it;
	it = outdoors.find(s);
	if (it == outdoors.end()) {
		std::cerr << "Bad writing of the month you are looking for. Please write the full name of the month and begin with an uppercase." << std::endl;
	}
	else it->second = b;
}

void Plant::setHarvest(std::string s, bool b) {
	std::map<std::string, bool>::iterator it;
	it = harvest.find(s);
	if (it == harvest.end()) {
		std::cerr << "Bad writing of the month you are looking for. Please write the full name of the month and begin with an uppercase." << std::endl;
	}
	else it->second = b;
}