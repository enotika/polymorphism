#include "Vodka.h"
string toString(—lassification f) {
	return VODKA_CLASS_NAMES[(int)f - 1];
}
void Vodka::set—lassification(—lassification a—lassification)
{
	classification = a—lassification;
}

—lassification Vodka::get—lassification() const
{
	return classification;
}

void Vodka::readFromConsole(istream & is, ostream & os)
{
	Alcohol::readFromConsole(is, os);
	readVodkaFromConsole(is, os);
}


void Vodka::readVodkaFromConsole(istream & is, ostream & os)
{
	int t;
	os << VODKA_STRING << endl;
	while (true) {
		is >> t;
		if (!((t < 1) || (t > CLASS_COUNT))) {
			break;
		}
		os << "Wrong input! Try again... (class must be between 1 and " << CLASS_COUNT << ")\n";
	}
	set—lassification((—lassification)t);
}

Vodka::Vodka(string aName, double aDegree, double aPrice, —lassification a—lassification) :
	Alcohol(aName, aDegree, aPrice)
{
	set—lassification(a—lassification);
}

Vodka::Vodka()
{
	setName("#");
	setDegree(0);
	setPrice(0);
	set—lassification(—lassification(1));
}

void Vodka::writeToStream(ostream & os)
{
	if (name == "#") {
		os << "Vodka : This element wasn't set\n";
	}
	else {
		os << "Vodka: " << (const Alcohol&)*this << " Classification: " <<
			toString(classification) << "\n";
	}
}

ostream & operator<<(ostream & os, const Vodka & b)
{
	if (b.name == "#") {
		os << "Vodka : This element wasn't set\n";
	}
	else {
		os << "Vodka: " << (const Alcohol&)b << " Classification: " << toString(b.classification) << "\n";
	}
	return os;
}
