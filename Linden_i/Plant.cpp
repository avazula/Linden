#include "Plant.hpp"

std::vector<bool> Plant::getEmptyArray() {

	//Declaring and initializing a vector of booleans with false values for the default constructor
	std::vector<bool> vec = { false,false,false,false,false,false,false,false,false,false,false,false };

	return vec;
}

void Plant::sortedDisplay(std::map<std::string, bool> m) {
	for (int i = 0; i < nbMonths; i++) {
		if (m[calendar[i]] == true) std::cout << " " << calendar[i];
	}
}

//Check whether the selected month is good for sowing or harvesting
bool Plant::isOkIndoors(std::string s) {

	std::map<std::string, bool>::iterator it;
	it = indoors.find(s);
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

bool Plant::getIndoors(std::map <std::string, bool>::iterator it) {
	//if (i > nbMonths-1) {
	//	std::cerr << "Please choose an integer between 0 and 11" << std::endl;
	//}
	//std::map<std::string, bool>::iterator it = indoors.begin();
	return it->second;
}

bool Plant::getOutdoors(std::map <std::string, bool>::iterator it) {
	return it->second;
}

bool Plant::getHarvest(std::map <std::string, bool>::iterator it) {
	return it->second;
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