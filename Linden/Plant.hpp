#ifndef PLANT_HPP_
#define PLANT_HPP_

#include <iostream>
#include <string>
#include <array>

class Plant {

protected:
	//Constant global attribute for the size of the boolean arrays
	static const int nbMonths = 12;
	static const int nbTreats = 3;

	std::string name;

	std::array<std::string, nbMonths> calendar = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	std::array<bool, nbMonths> indoors;
	std::array<bool, nbMonths> outdoors;
	std::array<bool, nbMonths> harvest;

public:
	//Creates a plant whose only attribute is a name
	Plant(std::string n = '\0') : name(n) {}

	Plant(std::string n, std::array<bool, nbMonths> in, std::array<bool, nbMonths> out, std::array<bool, nbMonths> harv) : name(n) {
		for (int i = 0; i < nbMonths; i++) {
			this->indoors[i] = in[i];
		}

		for (int i = 0; i < nbMonths; i++) {
			this->outdoors[i] = out[i];
		}

		for (int i = 0; i < nbMonths; i++) {
			this->harvest[i] = harv[i];
		}
	}

	void display();
	bool isOkIndoors(unsigned int i);
	bool isOkOutdoors(unsigned int i);
	bool isOkHarvest(unsigned int i);
	
	virtual void setType(Plant& p);
	virtual void setTreatment(Plant& p);

	//~Plant() {
	//	delete indoors, outdoors, harvest;
	//}
};

#endif PLANT_HPP_