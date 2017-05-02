#ifndef HERB_HPP_
#define HERB_HPP_


#include "Plant.hpp"

//Derived Herb class based on Plant class
class Herb : public Plant {

private:

	//Type of the plant
	static const std::string type;
	//Boolean that indicates whether the herb is perrenial (true) or annual (false)
	bool perrenial;

public:
	//Constructor
	Herb(std::string n = "", std::vector<bool> in = getEmptyArray(), std::vector<bool> out = getEmptyArray(), std::vector<bool> harv = getEmptyArray(), bool p = false) : Plant(n, in, out, harv), perrenial(p) {}

	//Method for creating new objects of the class (please refer to the Factory cpp files)
	static Plant * __stdcall Create(std::string n, std::vector<bool> in, std::vector<bool> out, std::vector<bool> harv, bool m);

	//display() function that was pure virtual in Plant class
	void display();

	//Pure virtual accessors from Plant class
	std::string getType(const Plant& p);

	//Accessors specific to the Herb class
	bool getPerrenial(const Herb& h);

	//Mutators specific to the Herb class
	void setPerrenial(bool b);

};

#endif HERB_HPP_