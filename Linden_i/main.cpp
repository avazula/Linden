#include "Fruit.hpp"
#include "Herb.hpp"
#include "Legume.hpp"
#include "Vegetable.hpp"
//#include "Factory.hpp"

#include <iostream>
#include <sstream>
#include <ostream>
#include <map>
#include <utility>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	cout << "Hello world!" << endl;

	/*string calendar[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	vector<bool> ind = { 1,0,0,1,1,1,0,1,0,0,1,0 };
	vector<bool> outd = { 1,1,1,0,1,1,0,0,0,0,1,0 };
	vector<bool> harvs = { 0,1,0,1,0,1,0,1,0,1,0,1 };
	string name = "raspberry";

	Fruit p1("tree");
	Fruit p2("rapsberry", ind, outd, harvs, ind, outd);
	p1.display();
	p2.display();*/

	//Declaration of the name of the file to be read
	string myFile = "Data.txt";
	//Opening the file in reading mode in C++ style
	ifstream infile(myFile.c_str(), ios::in);

	if (infile) {
		//Declaration of a string to read each existing line of the line
		string line;

		string type, name;
		string ind, out, harv;
		vector<bool> indoors, outdoors, harvest;

		infile >> type >> name >> ind >> out >> harv;
		stringstream sind(ind), sout(out), sharv(harv);

		bool b;

		while (sind >> b) {
			indoors.push_back(b);
			if (sind.peek() == ',') {
				sind.ignore();
			}
		}

		while (sout >> b) {
			outdoors.push_back(b);
			if (sout.peek() == ',') {
				sout.ignore();
			}
		}

		while (sharv >> b) {
			harvest.push_back(b);
			if (sharv.peek() == ',') {
				sharv.ignore();
			}
		}

		Herb h(name, indoors, outdoors, harvest);
		h.display();

		/*GUIFactory* guiFactory;
		Plant* p;
		guiFactory = new Factory;

		p = guiFactory->createPlant("herb");
		p->display();*/

		infile.close();
	}
	else {
		cerr << "Opening of the file is impossible!" << endl;
	}

	//Test of Factory class
	/*GUIFactory* guiFactory;
	Plant* p;
	guiFactory = new Factory;

	p = guiFactory->createPlant("herb");
	p->display();*/


	/*void init() {

		std::string myFile = "Bleble.txt";
		std::ifstream infile(myFile.c_str(), std::ios::in);
		infile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try {
			infile.open(myFile);
			while (!infile.eof()) infile.get();
		}
		catch (const std::ifstream::failure& e) {
			std::cerr << "Error opening the file." << std::endl;
		}
	}*/

	system("PAUSE");

	return 0;
}