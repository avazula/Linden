#ifndef LEGUME_HPP_
#define LEGUME_HPP_

#include "Plant.hpp"

//Legume class derived from abstract class Plant
class Legume : public Plant {


private:

	//Type of the plant
	static const std::string type;
	//Boolean saying if the legume is likely to suffer from mildew
	bool mildew;

public:
	//Constructor
	Legume(std::string n = " ", std::vector<bool> in = getEmptyArray(), std::vector<bool> out = getEmptyArray(), std::vector<bool> harv = getEmptyArray(), bool m = false) : Plant(n, in, out, harv), mildew(m) {}
	//Method for creating new objects of the class (please refer to the Factory cpp files)
	static Plant * __stdcall Create(std::string n, std::vector<bool> in, std::vector<bool> out, std::vector<bool> harv, bool m);

	//display() function that was pure virtual in Plant class 
	void display();

	//Pure virtual accessors declared in class Plant
	std::string getType(const Plant& p);

	//Accessors
	bool getMildew(const Legume& l);

	//Mutators
	void setMildew(Legume& l, bool m);
};

#endif LEGUME_HPP_