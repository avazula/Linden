#include "Fruit.hpp"
#include "Herb.hpp"
#include "Legume.hpp"
#include "Vegetable.hpp"
#include "Factory.hpp"

#include <iostream>
#include <sstream>
#include <ostream>
#include <map>
#include <utility>
#include <vector>
#include <fstream>
//Header for exceptions when dealing with a ifstream object
#include <stdexcept>

using namespace std;

int main()
{
	//Exception management: trying to open the file in reading mode.
	try {
		//Declaration of the name of the file to be read
		string myFile = "Data.txt";
		//Opening the file in reading mode in C++ style
		ifstream infile(myFile.c_str(), ios::in);

		//If it is possible, then let us notify the user
		if (infile) {
			cout << "Successful opening of the file. Loading of the program." << endl;
		}
	}
	//Else, let us display an error message explaining the exception that was thrown.
	catch (const std::exception& e) {
		cerr << "Exception " << e.what() << endl;
	}

	//String containing the name of the file to read
	string myFile = "Data.txt";
	//Opening under read-only configuration
	ifstream infile(myFile.c_str(), ios::in);

	//Vectors where the derived plants will be stored.
	vector<Fruit> fruits;
	vector<Herb> herbs;
	vector<Legume> legumes;
	vector<Vegetable> vegetables;

	if (infile) {
		//Declaration of a string to read each existing line of the line
		string line;

		//Declaring a string for each parameter that we could find on a given line
		string type, name, ind, out, harv, root, pru, dist, mil, pow, per;
		//Declaration of the vectors needed to initialize the related maps in the constructors
		vector<bool> indoors, outdoors, harvest, rootStocking, pruning;

		float distance;
		bool mildew = 0;
		bool powderyMildew = 0;
		bool perrenial = 0;

		//While the end of the file is not reached
		while (getline(infile, line)) {

			//Loading the read words in the defined strings. 
			//Whenever a SPACE is encountered, this corresponds to a new word (hence a new string).
			infile >> type >> name >> ind >> out >> harv >> root >> pru >> dist >> mil >> pow >> per;
			//Declaration of the stringstreams needed for parsing.
			/*To go further with this, let us look at the way the data about indoors (for instance) is stored in the datafile.
			For now we have loaded this data into a single string but this word is composed of 12 booleans and 11 delimiting commas.
			To get a vector of booleans from this string we need to parse it using stringstream. This is the same reasoning that is held 
			for the distance float or the booleans (everything that is not supposed to be used as a string, in a nutshell).*/
			stringstream sind(ind), sout(out), sharv(harv), sroot(root), spru(pru), sdist(dist), smil(mil), spow(pow), sper(per);

			bool b;
			
			//While we have not reached the end of the word ->
			//While we still can load a boolean from the values stored in the word
			while (sind >> b) {
				//Take this character of the string and store it as a boolean at the corresponding place in the vector
				indoors.push_back(b);
				//If we encounter a comma then just 'skip' it
				if (sind.peek() == ',') sind.ignore();
			}

			//This is the same idea for the outdoors, harvest, pruning and rootstocking vectors
			while (sout >> b) {
				outdoors.push_back(b);
				if (sout.peek() == ',') sout.ignore();
			}

			while (sharv >> b) {
				harvest.push_back(b);
				if (sharv.peek() == ',') sharv.ignore();
			}

			/*Not all plants have relevant data about rootstocking. If the string root contains an only 'n' then 
			it means that this data is not relevant for the given plant, so we must ignore it.*/
			if (root.compare("n") == 0) {
				//Saying that the data is not relevant can be translated into: "we will never be able to do any rootstocking with this plant",
				//hence we fill the vector with 0s (false).
				for (int i = 0; i < 12; i++) rootStocking.push_back(0);
			}
			else {
				while (sroot >> b) {
					rootStocking.push_back(b);
					if (sroot.peek() == ',') sroot.ignore();
				}
			}
			//This is the same idea as above
			if (pru.compare("n") == 0) {
				for (int i = 0; i < 12; i++) pruning.push_back(0);
			}
			else {
				while (spru >> b) {
					pruning.push_back(b);
					if (spru.peek() == ',') spru.ignore();
				}
			}

			//If the data is relevant then store it, otherwise initialize it to 0.
			if (dist.compare("n") == 0) distance = 0.0;
			else sdist >> distance;
			//If the data is relevant then store it, otherwise initialize it to 0.
			if (mil.compare("n") == 0) mildew = 0;
			else smil >> mildew;
			//If the data is relevant then store it, otherwise initialize it to 0.
			if (pow.compare("n") == 0) powderyMildew = 0;
			else spow >> powderyMildew;
			//If the data is relevant then store it, otherwise initialize it to 0.
			if (per.compare("n") == 0) perrenial = 0;
			else sper >> perrenial;

			//I did not succeed to manage the creation of all plants by using the factory because it led me to a exception thrown when I was 
			//trying to display the created objects. I however let the code here because I think that this is an interesting way of instantiating
			//objects and that I would have been closed from the solution.

			/*Plant * p;
			Declaration of the factory
			Factory * fc;
			fc = new Factory;
			This calls the appropriate Create function depending on the type. As all parameters (that were loaded before) are given
			as parameters of the createPlant function, we can instantiate objects with relevant data for all its attributes.
			p = fc->createPlant(type, name, indoors, outdoors, harvest, rootStocking, pruning, distance, mildew, powderyMildew, perrenial);
			Storing of a pointer to the created object into a map: they key is the name of the plant and the value is the pointer.
			plants.insert(std::pair<string, Plant*>(p->getName(*p), p));*/

			//Creation of all objects depending on their type and storing them in the appropriate vectors
			if (type.compare("herb") == 0) {
				Herb h(name, indoors, outdoors, harvest, perrenial);
				herbs.push_back(h);
			}
			else if (type.compare("fruit") == 0) {
				Fruit f(name, indoors, outdoors, harvest, rootStocking, pruning, mildew);
				fruits.push_back(f);
			}
			else if (type.compare("legume") == 0) {
				Legume l(name, indoors, outdoors, harvest, mildew);
				legumes.push_back(l);
			}
			else if (type.compare("vegetable") == 0) {
				Vegetable v(name, indoors, outdoors, harvest, distance, mildew, powderyMildew);
				vegetables.push_back(v);
			}
		}
		//Reading and instantiating is over, closing of the file
		infile.close();

		//Test of the creation of the plants: displaying of their data
		//for (vector<Fruit>::iterator it = fruits.begin(); it != fruits.end(); ++it) {
		//	(*it).display();
		//}
		//for (vector <Herb>::iterator it = herbs.begin(); it != herbs.end(); ++it) {
		//	(*it).display();
		//}
		//for (vector <Legume>::iterator it = legumes.begin(); it != legumes.end(); ++it) {
		//	(*it).display();
		//}
		//for (vector <Vegetable>::iterator it = vegetables.begin(); it != vegetables.end(); ++it) {
		//	(*it).display();
		//}

	}

	//Core of the program
	cout << "________________________________________________________________________________" << endl << endl;
	cout << "                    G A R D E N I N G   M A N A G E R                           " << endl;
	cout << "________________________________________________________________________________" << endl << endl;

	//Choices offered to the user
	cout << "Welcome to the gardening manager.\nWith this software you can either:" << endl << endl;
	cout << "1. Look for a plant and all the related data" << endl;
	cout << "2. Discover what to sow indoors on a specific month" << endl;
	cout << "3. Discover what to sow outdoors on a specific month" << endl;
	cout << "4. Discover what to harvest on a specific month" << endl;
	cout << "5. Discover the plants for which you can do rootstocks" << endl;
	cout << "6. Discover the plants that you need to prune." << endl << endl;
	cout << "Please make a choice by entering a number between 1 and 6 or press 0 for exit." << endl;

	//Vector for checking if the month given by the user respects the defined syntax
	vector<string> year = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	Vegetable t("Tomato");
	t.display();
	float dist;
	cout << "Enter specific distance for " << t.getName(t) << ": " << endl;
	cin >> dist;
	t.setDistance(t, dist);
	t.display();

	cout << "The new set distance for " << t.getName(t) << " is: " << t.getDistance(t) << endl;

	int choice;
	while (1) {
		cin >> choice;
		//If 0 then exit.
		if (choice == 0) return 0;
		//Data about one specific plant
		else if (choice == 1) {
			//Name of the plant to look for
			string plant;
			cout << "Please enter the name of the plant you are looking for (e.g. Carrot):" << endl;
			//Logging it to the program
			cin >> plant;

			int sum = 0;
			//Searching each vector of plants to see if the plant is contained in it. If yes, then display() it.
			for (vector<Fruit>::iterator it = fruits.begin(); it != fruits.end(); ++it) {
				if ((*it).getName(*it).compare(plant) == 0) {
					(*it).display();
					//If the plant is found then sum is incremented.
					sum++;
				}
			}
			for (vector <Herb>::iterator it = herbs.begin(); it != herbs.end(); ++it) {
				if ((*it).getName(*it).compare(plant) == 0) {
					(*it).display();
					sum++;
				}
			}
			for (vector <Legume>::iterator it = legumes.begin(); it != legumes.end(); ++it) {
				if ((*it).getName(*it).compare(plant) == 0) {
					(*it).display();
					sum++;
				}
			}
			for (vector <Vegetable>::iterator it = vegetables.begin(); it != vegetables.end(); ++it) {
				if ((*it).getName(*it).compare(plant) == 0) {
					(*it).display();
					sum++;
				}
			}
			//If sum is equal to 0 it means that the plant has not been found. 
			if (sum == 0) cout << "The plant you are looking for does not exist in the program. Please try with another plant." << endl;
			cout << "Please make a choice by entering a number between 1 and 6 or press 0 for exit." << endl;
			cout << "Press 7 if you want to see the possibilities again." << endl;
		}
		//Data about all the plants that can be sowed indoors on a specific month
		else if (choice == 2) {
			string month;
			cout << "Please enter the month for which you look information about indoors sowing (e.g. February):" << endl;
			cin >> month;
			//Checking if the given month respects the defined syntax.
			vector<string>::iterator i;
			i = find(year.begin(), year.end(), month);
			if (i == year.end()) {
				std::cerr << "Bad writing of the month you are looking for. Please write the full name of the month and begin with an uppercase." << std::endl;
			}
			else {
				int sum = 0;
				for (vector<Fruit>::iterator it = fruits.begin(); it != fruits.end(); ++it) {

					if ((*it).getIndoors(month) == 1) {
						cout << it->getName(*it) << " ";
						sum++;
					}
				}
				for (vector<Herb>::iterator it = herbs.begin(); it != herbs.end(); ++it) {
					if (it->isOkIndoors(month)) {
						cout << it->getName(*it) << " ";
						sum++;
					}
				}
				for (vector<Legume>::iterator it = legumes.begin(); it != legumes.end(); ++it) {
					if (it->isOkIndoors(month)) {
						cout << it->getName(*it) << " ";
						sum++;
					}
				}
				for (vector<Vegetable>::iterator it = vegetables.begin(); it != vegetables.end(); ++it) {
					if (it->isOkIndoors(month)) {
						cout << it->getName(*it) << " ";
						sum++;
					}
				}
				if (sum == 0) cout << "There is nothing you can sow indoors in " << month << endl;
				else cout << "are the plants that you can sow indoors in " << month << endl;
				cout << "Please make a choice by entering a number between 1 and 6 or press 0 for exit." << endl;
				cout << "Press 7 if you want to see the possibilities again." << endl;

			}
		} //end choice 2: sowing indoors
		  //Data about all the plants that can be sowed outdoors on a specific month
		else if (choice == 3) {
			string month;
			cout << "Please enter the month for which you look information about outdoors sowing (e.g. February):" << endl;
			cin >> month;
			vector<string>::iterator i;
			i = find(year.begin(), year.end(), month);
			if (i == year.end()) {
				std::cerr << "Bad writing of the month you are looking for. Please write the full name of the month and begin with an uppercase." << std::endl;
			}
			else {

				int sum = 0;
				for (vector<Fruit>::iterator it = fruits.begin(); it != fruits.end(); ++it) {
					if (it->isOkOutdoors(month)) {
						cout << it->getName(*it) << " ";
						sum++;
					}
				}
				for (vector<Herb>::iterator it = herbs.begin(); it != herbs.end(); ++it) {
					if (it->isOkOutdoors(month)) {
						cout << it->getName(*it) << " ";
						sum++;
					}
				}
				for (vector<Legume>::iterator it = legumes.begin(); it != legumes.end(); ++it) {
					if (it->isOkOutdoors(month)) {
						cout << it->getName(*it) << " ";
						sum++;
					}
				}
				for (vector<Vegetable>::iterator it = vegetables.begin(); it != vegetables.end(); ++it) {
					if (it->isOkOutdoors(month)) {
						cout << it->getName(*it) << " ";
						sum++;
					}
				}
				if (sum == 0) cout << "There is nothing you can sow outdoors in " << month << endl;
				else cout << "are the plants that you can sow outdoors in " << month << endl;
				cout << "Please make a choice by entering a number between 1 and 6 or press 0 for exit." << endl;
				cout << "Press 7 if you want to see the possibilities again." << endl;

			}
		} //end choice 3: sowing outdoors
		  //Data about all the plants that can be harvested on a specific month
		else if (choice == 4)
		{
			string month;
			cout << "Please enter the month for which you look information about harvesting (e.g. February):" << endl;
			cin >> month;
			int sum = 0;
			vector<string>::iterator i;
			i = find(year.begin(), year.end(), month);
			if (i == year.end()) {
				std::cerr << "Bad writing of the month you are looking for. Please write the full name of the month and begin with an uppercase." << std::endl;
			}

			else {
				for (vector<Fruit>::iterator it = fruits.begin(); it != fruits.end(); ++it) {
					if (it->isOkHarvest(month)) {
						cout << it->getName(*it) << " ";
						sum++;
					}
				}
				for (vector<Herb>::iterator it = herbs.begin(); it != herbs.end(); ++it) {
					if (it->isOkHarvest(month)) {
						cout << it->getName(*it) << " ";
						sum++;
					}
				}
				for (vector<Legume>::iterator it = legumes.begin(); it != legumes.end(); ++it) {
					if (it->isOkHarvest(month)) {
						cout << it->getName(*it) << " ";
						sum++;
					}
				}
				for (vector<Vegetable>::iterator it = vegetables.begin(); it != vegetables.end(); ++it) {
					if (it->isOkHarvest(month)) {
						cout << it->getName(*it) << " ";
						sum++;
					}
				}
				if (sum == 0) cout << "There is nothing you can harvest in " << month << endl;
				else cout << "are the plants that you can harvest in " << month << endl;
				cout << "Please make a choice by entering a number between 1 and 6 or press 0 for exit." << endl;
				cout << "Press 7 if you want to see the possibilities again." << endl;

			}
		} //end choice 4: harvesting
		  //Data about all the plants for which you can do rootstocks on a specific month
		else if (choice == 5) {
			string month;
			cout << "Please enter the month for which you look information about rootstocking (e.g. February):" << endl;
			cin >> month;
			int sum = 0;
			vector<string>::iterator i;
			i = find(year.begin(), year.end(), month);
			if (i == year.end()) {
				std::cerr << "Bad writing of the month you are looking for. Please write the full name of the month and begin with an uppercase." << std::endl;
			}
			else {
				for (vector<Fruit>::iterator it = fruits.begin(); it != fruits.end(); ++it) {
					if (it->isOkRootstocking(month)) {
						cout << it->getName(*it) << " ";
						sum++;
					}
				}
				if (sum == 0) cout << "There is nothing you can rootstock in " << month << endl;
				else cout << "are the plants that you can rootstock in " << month << endl;
				cout << "Please make a choice by entering a number between 1 and 6 or press 0 for exit." << endl;
				cout << "Press 7 if you want to see the possibilities again." << endl;

			}
		} //end choice 5: rootstocking
		  //Data about all the plants for which you can prune on a specific month
		else if (choice == 6) {
			string month;
			cout << "Please enter the month for which you look information about pruning (e.g. February):" << endl;
			cin >> month;
			int sum = 0;
			vector<string>::iterator i;
			i = find(year.begin(), year.end(), month);
			if (i == year.end()) {
				std::cerr << "Bad writing of the month you are looking for. Please write the full name of the month and begin with an uppercase." << std::endl;
			}
			else {
				for (vector<Fruit>::iterator it = fruits.begin(); it != fruits.end(); ++it) {
					if (it->isOkPruning(month)) {
						cout << it->getName(*it) << " ";
						sum++;
					}
				}
				if (sum == 0) cout << "There is nothing you can prune in " << month << endl;
				else cout << "are the plants that you can prune in " << month << endl;
				cout << "Please make a choice by entering a number between 1 and 6 or press 0 for exit." << endl;
				cout << "Press 7 if you want to see the possibilities again." << endl;

			}
		} //end choice 6: pruning
		//Displaying of the "menu"
		else if (choice == 7) {
			cout << "1. Look for a plant and all the related data" << endl;
			cout << "2. Discover what to sow indoors on a specific month" << endl;
			cout << "3. Discover what to sow outdoors on a specific month" << endl;
			cout << "4. Discover what to harvest on a specific month" << endl;
			cout << "5. Discover the plants for which you can do rootstocks" << endl;
			cout << "6. Discover the plants that you need to prune." << endl << endl;
			cout << "Please make a choice by entering a number between 1 and 6 or press 0 for exit." << endl;
		}
		//If choice does not match any of these values then inform the user that it is a bad entry
		else if (choice < 0 || choice > 7) cout << "The number you have entered does not match the possible choices. Please enter a value between 1 and 6, press 7 for displaying the options or press 0 for exit." << endl;

	}
	system("PAUSE");
	return 0;
}