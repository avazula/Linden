#ifndef GUIFACTORY_HPP_
#define GUIFACTORY_HPP_

#include "Plant.hpp"

class GUIFactory {
public:
	virtual Plant *createPlant(char *) = 0;
};

#endif GUIFACTORY_HPP_
