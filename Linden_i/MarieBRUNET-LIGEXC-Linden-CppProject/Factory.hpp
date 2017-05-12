#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <map>
#include "Fruit.hpp"
#include "Herb.hpp"
#include "Legume.hpp"
#include "Vegetable.hpp"

class Factory {

private:
	//Declaration of the map to use for storing all the created plants from the reading of the datafile
	typedef std::map<std::string, Plant::CreatePlantFunc *> FactoryMap;
	FactoryMap myFactoryMap;

public:
	/*This method is related to the design pattern Factory. The idea is to call one unique function in the main
	to create all the needed objects, without having to care about the type of the plant.
	The following method 'createPlant' is based on the value of the type of the plant (that is the first string that will
	be read for each line of the 'Data.txt' file), and depending on this value, the createPlant method will call the
	associated Create function, that was defined in the derived classes.
	To avoid memory leaks, if the type does not match any the defined ones, the method will return a null pointer.
	The signature of the function takes all the possible parameters that could be needed for creating any of the derived plants. This is
	because in the Data.txt datafile, if a value is non-relevant for a Plant, then it has been affected value 'n', which means that there is
	nothing relevant here and that this parameter should be ignored for this line.*/
	Plant * createPlant(std::string t, std::string n, std::vector<bool> in, std::vector<bool> out, std::vector<bool> harv, std::vector<bool> r, std::vector<bool> p, float d, bool m, bool pm, bool pr);
};

#endif FACTORY_HPP_