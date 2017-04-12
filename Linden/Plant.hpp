#ifndef PLANT_HPP_
#define PLANT_HPP_

#include <iostream>
#include <string>

class Plant {
private:
	std::string name;
	bool* indoors;
	bool* outdoors;
	bool* harvest;
	static const int nbMonths = 12;

	Plant(std::string n, bool in[nbMonths], bool out[12], bool harv[12]) : name(n) {
		indoors = new bool[nbMonths];

	}
	~Plant();

public:

};

#endif PLANT_HPP_