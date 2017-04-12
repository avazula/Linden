#include <iostream>
#include "Plant.hpp"

using namespace std;
int main()
{
	cout << "Hello world!" << endl;

	bool ind[12]	= { 0,0,0,1,1,1,0,1,0,0,1,0 };
	bool outd[12]	= { 1,1,1,0,1,1,0,0,0,0,1,0 };
	bool harvs[12]	= { 0,1,0,1,0,1,0,1,0,1,0,1 };
	string name = "Raspberry";
	
	Plant p1("Tree");
	Plant p2(name, ind, outd, harvs);

	p1.display();
	p2.display();

	system("PAUSE");

	return 0;
}