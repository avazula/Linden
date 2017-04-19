#include "Plant.hpp"

void Plant::display() {
	std::cout << "Name of the plant: " << name << std::endl;

	std::cout << "Data about sowing indoors: " << std::endl;
	for (int i = 0; i < nbMonths-1; i++) {
		std::cout << this->calendar[i] << ": ";
		if (this->indoors[i] == true) {
			std::cout << "yes" << std::endl;
		}
		else {
			std::cout << "no" << std::endl;
		}
	}
	
	std::cout << "Data about sowing outdoors:" << std::endl;
	for (int i = 0; i < nbMonths - 1; i++) {
		std::cout << this->calendar[i] << ": ";
		if (this->outdoors[i] == true) {
			std::cout << "yes" << std::endl;
		}
		else {
			std::cout << "no" << std::endl;
		}
	}

	std::cout << "Data about harvesting:" << std::endl;
	for (int i = 0; i < nbMonths - 1; i++) {
		std::cout << this->calendar[i] << ": ";
		if (this->harvest[i] == true) {
			std::cout << "yes" << std::endl;
		}
		else {
			std::cout << "no" << std::endl;
		}
	}
	/*More black magic to come soon*/
}

bool Plant::isOkIndoors(unsigned int i) {
	if (i > Plant::nbMonths) {
		std::cerr << "Error: the number you've entered does not correspond to any month of the year.\n Try something between 0 and 11" << std::endl;
	}
	if (this->indoors[i] == 0) return false;
	else return true;
}

bool Plant::isOkOutdoors(unsigned int i) {
	if (i > Plant::nbMonths) {
		std::cerr << "Error: the number you've entered does not correspond to any month of the year.\n Try something between 0 and 11" << std::endl;
	}
	if (this->outdoors[i] == 0) return false;
	else return true;
}

bool Plant::isOkHarvest(unsigned int i) {
	if (i > Plant::nbMonths) {
		std::cerr << "Error: the number you've entered does not correspond to any month of the year.\n Try something between 0 and 11" << std::endl;
	}
	if (this->harvest[i] == 0) return false;
	else return true;
}
void Plant::setType(Plant& p) {}

void Plant::setTreatment(Plant& p) {}