#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Alcohol.h"
#include "Beer.h"
#include "Cognac.h"
#include "Vodka.h"
#include "Wine.h"
using namespace std;
const string CLASS_BEER = "class Beer";
const string CLASS_COGNAC = "class Cognac";
const string CLASS_VODKA = "class Vodka";
const string CLASS_WINE = "class Wine";
map < string, int > order;
void makeOrder(string s1, string s2, string s3, string s4) {
	order[s1] = 1;
	order[s2] = 2;
	order[s3] = 3;
	order[s4] = 4;
}
bool comp(Alcohol* a, Alcohol* b) {
	int a1 = order[string(typeid(*a).name())];
	int b1 = order[string(typeid(*b).name())];
	return (a1 < b1);
}
int main()
{
	makeOrder(CLASS_BEER, CLASS_COGNAC, CLASS_VODKA, CLASS_WINE);
	vector < Alcohol* > v;
	int n;
	cout << "Enter count of alcohol drinks\n";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "enter 1 to enter Beer, 2 to enter Cognac, 3 to enter Vodka, 4 to enter Wine\n";
		int type;
		cin >> type;
		if (type == 1) {
			Beer* b = new Beer();
			cin.ignore();
			b->readFromConsole(cin, cout);
			v.push_back(b);
		}
		if (type == 2) {
			Cognac* cg = new Cognac();
			cin.ignore();
			cg->readFromConsole(cin, cout);
			v.push_back(cg);
		}
		if (type == 3) {
			Vodka* vd = new Vodka();
			cin.ignore();
			vd->readFromConsole(cin, cout);
			v.push_back(vd);
		}
		if (type == 4) {
			Wine* wn = new Wine();
			cin.ignore();
			wn->readFromConsole(cin, cout);
			v.push_back(wn);
		}
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < n; i++) {
		v[i]->writeToStream(cout);
		delete v[i];
	}
}
