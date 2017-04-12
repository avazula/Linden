#ifndef PLANT_HPP_
#define PLANT_HPP_

#include <iostream>
#include <string>

class Plant {

private:
	//Constant global attribute for the size of the boolean arrays
	static const int nbMonths = 12;

	std::string name;

	bool* indoors;
	bool* outdoors;
	bool* harvest;

public:
	//Creates a plant whose only attribute is a name
	Plant(std::string n = '\0') : name(n) {}

	Plant(std::string n, bool in[nbMonths], bool out[nbMonths], bool harv[nbMonths]) : name(n) {

		indoors = (bool*)malloc(nbMonths * sizeof(bool));
		for (int i = 0; i < nbMonths; i++) {
			indoors[i] = in[i];
		}

		outdoors = (bool*)malloc(nbMonths * sizeof(bool));
		for (int i = 0; i < nbMonths; i++) {
			outdoors[i] = out[i];
		}

		harvest = (bool*)malloc(nbMonths * sizeof(bool));
		for (int i = 0; i < nbMonths; i++) {
			harvest[i] = harv[i];
		}
	}

	void display();
	
	virtual void setType(Plant& p);

	//~Plant() {
	//	delete indoors, outdoors, harvest;
	//}
};

#endif PLANT_HPP_