#include "Fruit.hpp"

const std::string Fruit::type = "fruit";

void Fruit::display() {
	std::cout << "Name of the plant: " << name << std::endl;
	std::cout << "This plant is of type: " << type << std::endl;

	/*Some fruits do not need to be sowed indoors, hence the creation of
	a variable cond that checks in there is any month for which it is
	good to sow this fruit indoors.*/
	int cond = 0;
	for (std::map<std::string, bool>::iterator it = indoors.begin(); it != indoors.end(); ++it) {
		if ((*it).second == true) cond++;
	}

	/*If the fruit is indeed likely to be sowed indoors,
	then display these months.*/
	if (cond != 0) {
		std::cout << name << " should rather be sowed indoors in";
		sortedDisplay(indoors);
		std::cout << "." << std::endl;
	}

	std::cout << name << " is likely to be sowed outdoors in";
	sortedDisplay(outdoors);
	std::cout << std::endl;

	std::cout << "You should harvest " << name << " in";
	sortedDisplay(harvest);
	std::cout << std::endl;

	cond = 0;
	for (std::map<std::string, bool>::iterator it = rootStocking.begin(); it != rootStocking.end(); ++it) {
		if ((*it).second == true) cond++;
	}

	/*If the fruit can be rootstocked,
	then display these months.*/
	if (cond != 0) {
		std::cout << name << " can be rootstocked. If you want to do so, then the best period for rootstoking this fruit tree is in ";
		sortedDisplay(rootStocking);
		std::cout << "." << std::endl;
	}

	/*If the considered fruit comes from a tree, then this latter should be pruned sometimes, hence
	the same reasoning as before for sowing indoors or for rootstocking.*/
	cond = 0;
	for (std::map<std::string, bool>::iterator it = pruning.begin(); it != pruning.end(); ++it) {
		if ((*it).second == true) cond++;
	}

	/*If the fruit is likely to be pruned,
	then display these months.*/
	if (cond != 0) {
		std::cout << name << " should be pruned sometimes. The best period for pruning this tree fruit is in ";
		sortedDisplay(pruning);
		std::cout << "." << std::endl;
	}
	std::cout << "The " << name << " is ";
	if (mildew == true) {
		std::cout << "likely";
	}
	else if (mildew == false) {
		std::cout << "not likely";
	}
	std::cout << " to suffer from mildew." << std::endl;

	std::cout << "The " << name << " is ";
	if (powderyMildew == true) {
		std::cout << "likely";
	}
	else if (powderyMildew == false) {
		std::cout << "not likely";
	}
	std::cout << " to suffer from powdery mildew" << std::endl;
}

std::string Fruit::getType(const Plant& p) {
	return type;
}

bool Fruit::getRootStocking(std::string s)
{
	return rootStocking[s];
}

bool Fruit::getPruning(std::string s)
{
	return pruning[s];
}

bool Fruit::getMildew(const Fruit & f)
{
	return f.mildew;
}

bool Fruit::getPowderyMildew(const Fruit & f)
{
	return f.powderyMildew;
}

void Fruit::setRootStocking(std::string s, bool b)
{
	rootStocking[s] = b;
}

void Fruit::setPruning(std::string s, bool b)
{
	pruning[s] = b;
}

