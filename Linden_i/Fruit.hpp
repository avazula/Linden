#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include "Plant.hpp"

class Fruit : public Plant {

private:

	//Type of the plant, hence fruit
	static const std::string type;

	//A map that indicates the best period for rootstocking.
	std::map<std::string, bool> rootStocking;
	//A map that indicates the best period for pruning the fruit tree.
	std::map<std::string, bool> pruning;

	//The following booleans indicate if the fruit is likely to suffer from mildew or powdery mildew.
	bool mildew;
	bool powderyMildew;

public:
	//The following constructor is based on the Plant's one and adds the rootstocking, pruning and (powdery) mildew data
	Fruit(std::string n = " ", std::vector<bool> in = getEmptyArray(), std::vector<bool> out = getEmptyArray(), std::vector<bool> harv = getEmptyArray(), std::vector<bool> r = getEmptyArray(), std::vector<bool> p = getEmptyArray(), bool m = false, bool pm = false) : Plant(n, in, out, harv), mildew(m), powderyMildew(pm) {
		for (int i = 0; i < nbMonths; i++) {
			rootStocking.insert(std::pair<std::string, bool>(calendar[i], r[i]));
			pruning.insert(std::pair<std::string, bool>(calendar[i], p[i]));
		}
	}

	static Plant * __stdcall Create(std::string n, std::vector<bool> in, std::vector<bool> out, std::vector<bool> harv, std::vector<bool> root, std::vector<bool> pru, bool m, bool pm);

	void display();

	bool isOkRootstocking(std::string s);
	bool isOkPruning(std::string s);

	//Pure virtual accessors declared in class Plant
	std::string getType(const Plant& p);

	//Accessors specific to the Fruit class
	bool getRootStocking(std::string s);
	bool getPruning(std::string s);
	bool getMildew(const Fruit& f);
	bool getPowderyMildew(const Fruit& f);

	//Mutators specific to the Fruit class
	void setRootStocking(std::string s, bool b);
	void setPruning(std::string s, bool b);

};

#endif FRUIT_HPP_