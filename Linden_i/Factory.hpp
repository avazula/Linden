#ifndef FACTORY_HPP_
#define FACTORY_HPP_

class Factory : public GUIFactory {

public:
	Plant * createPlant(char* type) {
		if (strcmp(type, "herb") == 0) return new Herb;
		else if (strcmp(type, "fruit") == 0) return new Fruit;
		else if (strcmp(type, "legume") == 0) return new Legume;
		else if (strcmp(type, "vegetable") == 0) return new Vegetable;
	}
};

#endif FACTORY_HPP_