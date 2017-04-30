#ifndef LEGUME_HPP_
#define LEGUME_HPP_

#include "Plant.hpp"

class Legume : public Plant {


private:

	//Type of the plant
	static const std::string type;
	bool mildew;

public:
	//Same constructor as for the Plant class, except for the treatments array, that we also need to initialize here
	Legume(std::string n = '\0', std::vector<bool> in = getEmptyArray(), std::vector<bool> out = getEmptyArray(), std::vector<bool> harv = getEmptyArray(), bool m = false) : Plant(n, in, out, harv), mildew(m) {}
	static Plant * __stdcall Create(std::string n, std::vector<bool> in, std::vector<bool> out, std::vector<bool> harv, bool m);

	//Overriding of the display function, as a Fruit has some more information to display than a Plant
	void display();

	//Pure virtual accessors declared in class Plant
	std::string getType(const Plant& p);

	bool getMildew(const Legume& l);

	void setMildew(Legume& l, bool m);
};

#endif LEGUME_HPP_