#ifndef HERB_HPP_
#define HERB_HPP_


#include "Plant.hpp"

class Herb : public Plant {

private:

	//Type of the plant
	static const std::string type;
	//Boolean that indicates whether the herb is perrenial (true) or annual (false)
	bool perrenial;

public:
	Herb(std::string n = "", std::vector<bool> in = getEmptyArray(), std::vector<bool> out = getEmptyArray(), std::vector<bool> harv = getEmptyArray(), bool p = false) : Plant(n, in, out, harv), perrenial(p) {}

	//Overriding of the display function, as a Fruit has some more information to display than a Plant
	void display();

	std::string getType();

	//Accessors specific to the Herb class
	bool getPerrenial(const Herb& h);

	//Mutators specific to the Herb class
	void setPerrenial(bool b);

};

#endif HERB_HPP_