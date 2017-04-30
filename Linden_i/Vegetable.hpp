#ifndef VEGETABLE_HPP_
#define VEGETABLE_HPP_

#include "Plant.hpp"

class Vegetable : public Plant {

private:

	//Type of the plant
	static const std::string type;
	bool mildew;
	bool powderyMildew;

	std::map<std::string,bool> thinning;
	//The vegetables need to be planted at a certain distance away from each other
	float distance;

public:

	Vegetable(std::string n = '\0', std::vector<bool> in = getEmptyArray(), std::vector<bool> out = getEmptyArray(), std::vector<bool> harv = getEmptyArray(), std::vector<bool> t = getEmptyArray(), float d = 0.0, bool m = false, bool pm = false) : Plant(n, in, out, harv), distance(d), mildew(m), powderyMildew(pm) {
		for (int i = 0; i < nbMonths; i++) {
			thinning.insert(std::pair < std::string,bool>(calendar[i], t[i]));
		}
	}

	static Plant * __stdcall Create(std::string n, std::vector<bool> in, std::vector<bool> out, std::vector<bool> harv, std::vector<bool> thi, float d, bool m, bool pm);
	
	//Overriding of the display function, as a Fruit has some more information to display than a Plant
	void display();

	//Pure virtual accessors declared in class Plant
	std::string getType(const Plant& p);

	//Accessors specific to class Vegetable
	float getDistance(const Vegetable& v);
	bool getMildew(const Vegetable& v);
	bool getPowderyMildew(const Vegetable& v);
	bool getThinning(std::map <std::string, bool>::iterator it);
	
	//Mutators specific to class Vegetable
	void setDistance(Vegetable& v, float d);
	void setMildew(Vegetable &v, bool m);
	void setPowderyMildew(Vegetable& v, bool pm);
	void setThinning(std::string s, bool b);

};
#endif VEGETABLE_HPP_