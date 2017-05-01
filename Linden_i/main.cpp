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
			cout << "Successful opening of the file." << endl;
		}

	}
	//Else, let us display an error message explaining the exception that was thrown.
	catch (const std::exception& e) {
		cerr << "Exception " << e.what() << endl;
	}

	string myFile = "Data.txt";
	ifstream infile(myFile.c_str(), ios::in);
	vector<Fruit> fruits;
	vector<Herb> herbs;
	vector<Legume> legumes;
	vector<Vegetable> vegetables;

	if (infile) {
		//Declaration of a string to read each existing line of the line
		string line;

		string type, name, ind, out, harv, root, pru, dist, mil, pow, per;
		vector<bool> indoors, outdoors, harvest, rootStocking, pruning;
		float distance;
		bool mildew = 0;
		bool powderyMildew = 0;
		bool perrenial = 0;

		//While the end of the file is not reached
		while (getline(infile, line)) {

			infile >> type >> name >> ind >> out >> harv >> root >> pru >> dist >> mil >> pow >> per;
			stringstream sind(ind), sout(out), sharv(harv), sroot(root), spru(pru), sdist(dist), smil(mil), spow(pow), sper(per);

			bool b;

			while (sind >> b) {
				indoors.push_back(b);
				if (sind.peek() == ',') sind.ignore();
			}

			while (sout >> b) {
				outdoors.push_back(b);
				if (sout.peek() == ',') sout.ignore();
			}

			while (sharv >> b) {
				harvest.push_back(b);
				if (sharv.peek() == ',') sharv.ignore();
			}

			if (root.compare("n") == 0) {
				for (int i = 0; i < 12; i++) rootStocking.push_back(0);
			}
			else {
				while (sroot >> b) {
					rootStocking.push_back(b);
					if (sroot.peek() == ',') sroot.ignore();
				}
			}

			if (pru.compare("n") == 0) {
				for (int i = 0; i < 12; i++) pruning.push_back(0);
			}
			else {
				while (spru >> b) {
					pruning.push_back(b);
					if (spru.peek() == ',') spru.ignore();
				}
			}

			if (dist.compare("n") == 0) distance = 0.0;
			else sdist >> distance;

			if (mil.compare("n") == 0) mildew = 0;
			else smil >> mildew;

			if (pow.compare("n") == 0) powderyMildew = 0;
			else spow >> powderyMildew;

			if (per.compare("n") == 0) perrenial = 0;
			else sper >> perrenial;

			/*Plant * p;
			Factory * fc;
			fc = new Factory;
			p = fc->createPlant(type, name, indoors, outdoors, harvest, rootStocking, pruning, distance, mildew, powderyMildew, perrenial);
			plants.insert(std::pair<string, Plant*>(p->getName(*p), p));*/

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

		infile.close();

		for (vector<Fruit>::iterator it = fruits.begin(); it != fruits.end(); ++it) {
			(*it).display();
		}
		for (vector <Herb>::iterator it = herbs.begin(); it != herbs.end(); ++it) {
			(*it).display();
		}
		for (vector <Legume>::iterator it = legumes.begin(); it != legumes.end(); ++it) {
			(*it).display();
		}
		for (vector <Vegetable>::iterator it = vegetables.begin(); it != vegetables.end(); ++it) {
			(*it).display();
		}

	}


	cout << "________________________________________________________________________________" << endl << endl;
	cout << "                    G A R D E N I N G   M A N A G E R                           " << endl;
	cout << "________________________________________________________________________________" << endl << endl;

	cout << "Welcome to the gardening manager.\nWith this software you can either:" << endl << endl;
	cout << "1. Look for a plant and all the related data" << endl;
	cout << "2. Discover what to sow indoors on a specific month" << endl;
	cout << "3. Discover what to sow outdoors on a specific month" << endl;
	cout << "4. Discover what to harvest on a specific month" << endl;
	cout << "5. Discover the plants for which you can do rootstocks" << endl;
	cout << "6. Discover the plants that you need to prune." << endl << endl;
	cout << "Please make a choice by entering a number between 1 and 6 or press 0 for exit." << endl;

	vector<string> year = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int choice;
	cin >> choice;
		//Data about one specific plant
		if (choice == 1) {
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
			if (sum == 0) cout << "The plant you are looking for does not exist in the program. Please try with another plant." << endl;
		}
		//Data about all the plants that can be sowed indoors on a specific month
		if (choice == 2) {
			string month;
			cout << "Please enter the month for which you look information about indoors sowing (e.g. February):" << endl;
			cin >> month;
			vector<string>::iterator i;
			i = find(year.begin(), year.end(), month);
			if(i == year.end()) {
				std::cerr << "Bad writing of the month you are looking for. Please write the full name of the month and begin with an uppercase." << std::endl;
			}
			else {
				int sum = 0;
				for (vector<Fruit>::iterator it = fruits.begin(); it != fruits.end(); ++it) {

					if (it->isOkIndoors(month)) {
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
			}	
		} //end choice 2: sowing indoors
		//Data about all the plants that can be sowed outdoors on a specific month
		if (choice == 3) {
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
			}
		} //end choice 3: sowing outdoors
		//Data about all the plants that can be harvested on a specific month
		if (choice == 4)
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
			}
		} //end choice 4: harvesting
		//Data about all the plants for which you can do rootstocks on a specific month
		if (choice == 5) {
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
				else cout << "are the plants that you can harvest in " << month << endl;
			}
		} //end choice 5: rootstocking
		//Data about all the plants for which you can prune on a specific month
		if (choice == 6) {
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
			}
		} //end choice 6: pruning
		else cout << "The number you have entered does not match the possible choices. Please enter a value between 1 and 6 or press 0 for exit." << endl;

	system("PAUSE");
	return 0;
}