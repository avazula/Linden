#ifndef VEGETABLE_HPP_
#define VEGETABLE_HPP_

#include "Plant.hpp"

//Derived class Vegetable based on abstract class Plant
class Vegetable : public Plant {

private:

	//Type of the plant
	static const std::string type;

	bool mildew;
	bool powderyMildew;

	//The vegetables need to be planted at a certain distance away from each other
	float distance;

public:
	//Constructor of the vegetable
	Vegetable(std::string n = '\0', std::vector<bool> in = getEmptyArray(), std::vector<bool> out = getEmptyArray(), std::vector<bool> harv = getEmptyArray(), float d = 0.0, bool m = false, bool pm = false) : Plant(n, in, out, harv), distance(d), mildew(m), powderyMildew(pm) { }

	//Method for creating new objects of the class (please refer to the Factory cpp files)
	static Plant * __stdcall Create(std::string n, std::vector<bool> in, std::vector<bool> out, std::vector<bool> harv, float d, bool m, bool pm);
	
	//display() method that was pure virtual in Plant class
	void display();

	//Pure virtual accessors declared in class Plant
	std::string getType(const Plant& p);

	//Accessors specific to class Vegetable
	float getDistance(const Vegetable& v);
	bool getMildew(const Vegetable& v);
	bool getPowderyMildew(const Vegetable& v);
	
	//Mutators specific to class Vegetable
	void setDistance(Vegetable& v, float d);
	void setMildew(Vegetable &v, bool m);
	void setPowderyMildew(Vegetable& v, bool pm);

};
#endif VEGETABLE_HPP_