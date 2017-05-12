#ifndef PLANT_HPP_
#define PLANT_HPP_

#include <iostream>
#include <string>
#include <map>
#include <vector>

//Abstract class Plant.
class Plant {

protected:
	//Constant attribute that indicates the size of the vectors associated with the months of the year
	static const int nbMonths = 12;
	//Array of strings for initializing the keys of the maps
	std::string calendar[nbMonths] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	//Name of the plant
	std::string name;

	/*These three maps indicate whether it is a good time
	to sow indoors, outdoors and for harvesting.
	If the boolean equals true, then something should be done during this month,
	otherwise it is not a good period for doing it.*/
	std::map<std::string, bool> indoors;
	std::map<std::string, bool> outdoors;
	std::map<std::string, bool> harvest;

	//Function for initializing the vectors filled with false value for the default parameters of the constructor
	static std::vector<bool> Plant::getEmptyArray();
	/*This function modifies the default behaviour of maps for displaying. Normally the displaying is ordered regarding to
	the complexity. sortedDisplay() allows the elements of the map to be displayed in the order in which they have been 
	inserted.*/
	void sortedDisplay(std::map<std::string, bool> m);

public:

	/*This function is a method for building new objects of the (derived) classes (because it is not
	possible to create objects from an abstract class.
	This method is used in the scope of the Factory design pattern (please see the related cpp files).*/
	typedef Plant * (__stdcall * CreatePlantFunc)(void);
	//Constructor with default parameters. If not specified, the vectors will be initialized with the false value, and the name will be empty
	Plant(std::string n = "", std::vector<bool> in = getEmptyArray(), std::vector<bool> out = getEmptyArray(), std::vector<bool> harv = getEmptyArray()) : name(n) {
		//Initializing the maps of sowing indoors, outdoors and harvesting
		for (int i = 0; i < nbMonths; i++) {
			indoors.insert(std::pair<std::string, bool>(calendar[i], in[i]));
			outdoors.insert(std::pair<std::string, bool>(calendar[i], out[i]));
			harvest.insert(std::pair<std::string, bool>(calendar[i], harv[i]));
		}
	}

	/*The display method is pure virtual because we assume that there is
	no meaning of creating a Plant.*/
	virtual void display() = 0;

	//Check whether the selected month is good for sowing or harvesting
	bool isOkIndoors(std::string s);
	bool isOkOutdoors(std::string s);
	bool isOkHarvest(std::string s);

	//Accessors
	std::string getName(const Plant& p);
	bool		getIndoors(std::string month);
	bool		getOutdoors(std::string month);
	bool		getHarvest(std::string month);

	/*This accessor has no meaning yet, because the type of a plant is related to the child
	classes derived of this latter, hence the pure virtual declaration.*/
	virtual std::string getType(const Plant& p) = 0;

	//Mutators
	void setName(std::string newName);
	void setIndoors(std::string s, bool b);
	void setOutdoors(std::string s, bool b);
	void setHarvest(std::string s, bool b);

};

#endif PLANT_HPP_