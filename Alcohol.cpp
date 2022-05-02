#include "Alcohol.h"

void Alcohol::clone(const Alcohol & other)
{
	name = other.name;
	degree = other.degree;
	price = other.price;
}

Alcohol::Alcohol(string aName, double aDegree, double aPrice)
{
	setName(aName);
	setDegree(aDegree);
	setPrice(aPrice);
}

Alcohol::Alcohol(const Alcohol & other)
{
	clone(other);
}

Alcohol::Alcohol()
{
	setName("#");
	setDegree(0);
	setPrice(0);
}

void Alcohol::setDegree(double aDegree)
{
	if (aDegree < 0) {
		throw exception("setDegree: invalid degree(degree must be more than 0)");
	}
	degree = aDegree;
}

void Alcohol::setPrice(double aPrice)
{
	if (aPrice < 0) {
		throw exception("setPrice: invalid price(price must be more than 0)");
	}
	price = aPrice;
}

void Alcohol::setName(string aName)
{
	name = aName;
}

double Alcohol::getDegree() const
{
	return degree;
}

double Alcohol::getPrice() const
{
	return price;
}

string Alcohol::getName() const
{
	return name;
}

void Alcohol::readFromConsole(istream& is, ostream& os)
{
	cout << "ALCOHOL !!!! \n";
	string s;
	os << "Enter alcohol name\n";
	getline(is, s);
	setName(s);
	os << "Enter alcohol degree\n";
	double deg;
	while (true) {
		is >> deg;
		try {
			setDegree(deg);
			break;
		}
		catch (exception&ex) {
			os << "Wrong input! Try again... " << ex.what() << endl;
		}
	}
	os << "Enter price\n";
	double pr;
	while (true) {
		is >> pr;
		try {
			setPrice(pr);
			break;
		}
		catch (exception&ex) {
			os << "Wrong input! Try again... " << ex.what() << endl;;
		}
	}
}

void Alcohol::writeToStream(ostream & os)
{
	if (name == "#") {
		os << "This element wasn't set\n";
	}
	else {
		os << " Name: " << name <<
			" Degree: " << degree << " Price: " << price << " ";
	}
}

ostream & operator<<(ostream & os, const Alcohol & b)
{
	if (b.name == "#") {
		os << "This element wasn't set\n";
	}
	else {
		os << " Name: " << b.name <<
			" Degree: " << b.degree << " Price: " << b.price << " ";
	}
	return os;
}
