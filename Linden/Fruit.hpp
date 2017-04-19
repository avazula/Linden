#ifndef FRUIT_HPP_
#define FRUIT_HPP_
#include <vector>
#include "Plant.hpp"

class Fruit : public Plant {

private:

	static const std::string type;
	std::vector<std::string> treatments;

public:

	void setType(Plant& p);
	void setTreatment(Plant& p);
	void display();

	Fruit(std::string n, std::array<bool, nbMonths> in, std::array<bool, nbMonths> out, std::array<bool, nbMonths> harv, std::string t) : Plant(n, in, out, harv) {}
	
};

#endif FRUIT_HPP_