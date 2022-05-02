#include "Wine.h"
string toString(WineType f) {
	return WINE_TYPE_NAMES[(int)f - 1];
}
void Wine::readWineFromConsole(istream & is, ostream & os)
{
	int t;
	os << WINE_MENU_STRING << endl;
	while (true) {
		is >> t;
		if (!((t < 1) || (t > WINE_TYPE_COUNT))) {
			break;
		}
		os << "Wrong input! Try again... (wine type must be between 0 and " << WINE_TYPE_COUNT << ")\n";
	}
	setWineType((WineType)t);
}

void Wine::setWineType(WineType aType)
{
	wineType = aType;
}

WineType Wine::getWineType() const
{
	return wineType;
}

void Wine::readFromConsole(istream & is, ostream & os)
{
	Alcohol::readFromConsole(is, os);
	readWineFromConsole(is, os);
}

void Wine::writeToStream(ostream & os)
{
	if (name == "#") {
		os << "Wine : This element wasn't set\n";
	}
	else {
		os << "Wine: " << (const Alcohol&)*this << " Wine Type: " << toString(wineType) << "\n";
	}
}

Wine::Wine(string aName, double aDegree, double aPrice, WineType aWineType) :
	Alcohol(aName, aDegree, aPrice)
{
	setWineType(aWineType);
}

Wine::Wine()
{
	setName("#");
	setDegree(0);
	setPrice(0);
	setWineType(WineType(1));
}

ostream & operator<<(ostream & os, const Wine & b)
{	
	if (b.name == "#") {
		os << "Wine : This element wasn't set\n";
	}
	else {
		os << "Wine: " << (const Alcohol&)b << " Wine Type: " << toString(b.wineType) << "\n";
	}
	return os;
}
