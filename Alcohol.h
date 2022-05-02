#pragma once
#include <string>
#include <iostream>
#include <exception>
using namespace std;
class Alcohol
{
protected:
	string name;
	double degree;
	double price;
	virtual void dummy() = 0;   // для обеспечения абстрактности класса
	void clone(const Alcohol& other);
public:
	Alcohol(string aName, double aDegree, double aPrice);
	Alcohol(const Alcohol& other);
	Alcohol();
	void setDegree(double aDegree);
	void setPrice(double aPrice);
	void setName(string aBrand);
	double getDegree() const;
	double getPrice() const;
	string getName() const;
	friend ostream& operator << (ostream& os, const Alcohol& b);
	virtual void readFromConsole(istream& is, ostream& os);
	virtual void writeToStream(ostream& os);
};

