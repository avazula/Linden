#include "Plant.hpp"
#include "Fruit.hpp"
#include "Herb.hpp"
#include "Legume.hpp"
#include "Vegetable.hpp"
#include "GUIFactory.hpp"
#include "Factory.hpp"
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

	//string myFile = "Data.txt";
	//ifstream infile(myFile.c_str(), ios::in);

	//if (infile) {
	//	string line;

	//	string type, name;
	//	string ind, out, harv;
	//	vector<bool> indoors, outdoors, harvest;

	//	infile >> type >> name >> ind >> out >> harv;
	//	stringstream sind(ind), sout(out), sharv(harv);

	//	bool b;

	//	while (sind >> b) {
	//		indoors.push_back(b);
	//		if (sind.peek() == ',') {
	//			sind.ignore();
	//		}
	//	}

	//	while (sout >> b) {
	//		outdoors.push_back(b);
	//		if (sout.peek() == ',') {
	//			sout.ignore();
	//		}
	//	}

	//	while (sharv >> b) {
	//		harvest.push_back(b);
	//		if (sharv.peek() == ',') {
	//			sharv.ignore();
	//		}
	//	}

	//	/*cout << "Size of indoors is: " << indoors.size() <<endl;
	//	cout << indoors.at(4);*/

	//	if (type == "herb") {
	//		Herb h(name, indoors, outdoors, harvest);
	//		h.display();
	//	}


	//	/*while (getline(infile, line)) {
	//		cout << line << endl;
	//	}*/

	//	infile.close();
	//}
	//else {
	//	cerr << "Opening of the file is impossible!" << endl;
	//}

	GUIFactory* guiFactory;
	Plant* p;
	guiFactory = new Factory;

	p = guiFactory->createPlant("herb");
	p->display();

	system("PAUSE");

	return 0;
}