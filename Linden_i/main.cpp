#include "Plant.hpp"
#include "Fruit.hpp"
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

	string myFile = "Data.txt";
	ifstream infile(myFile.c_str(), ios::in);

	if (infile) {
		/*string line;*/

		/*string type, name;
		string ind;
		vector<bool> test;

		infile >> type >> name >> ind;
		for (char& c : ind) {

		}
*/
		/*while (getline(infile, line)) {
			cout << line << endl;
		}*/

		infile.close();
	}
	else {
		cerr << "Opening of the file is impossible!" << endl;
	}

	system("PAUSE");

	return 0;
}