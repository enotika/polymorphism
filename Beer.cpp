#include "Beer.h"
string toString(Type f) {
	return TYPE_NAMES[(int)f - 1];
}
void Beer::readBeerFromConsole(istream & is, ostream & os)
{
	int t;
	os << BEER_MENU_STRING << endl;
	while (true) {
		is >> t;
		if (!((t < 1) || (t > TYPE_COUNT))) {
			break;
		}
		os << "Wrong input! Try again...(beer type must be between 1 & " << TYPE_COUNT << ")\n";
	}
	setType((Type)t);
	os << "Enter bitterness of beer\n";
	while (true) {
		is >> t;
		try {
			setBitterness(t);
			break;
		}
		catch (exception&ex) {
			os << "Wrong input! Try again... " << ex.what() << endl;
		}
	}
}
Beer::Beer(string aBrand, double aDegree, double aPrice, Type aType, int aBitterness):
	Alcohol(aBrand, aDegree, aPrice)
{
	setType(aType);
	setBitterness(aBitterness);
}

Beer::Beer()
{
	setName("#");
	setDegree(0);
	setPrice(0);
	setType(Type(1));
	setBitterness(0);
}

void Beer::setType(Type aType)
{
	type = aType;
}

Type Beer::getType() const
{
	return type;
}

void Beer::setBitterness(int aBitterness)
{
	if (aBitterness < 0) {
		throw exception("setBitterness : invalid bitterness(bitternes must be more than 0)");
	}
	bitterness = aBitterness;
}

int Beer::getBitterness() const
{
	return bitterness;
}

void Beer::readFromConsole(istream & is, ostream & os)
{
	Alcohol::readFromConsole(is, os);
	readBeerFromConsole(is, os);
}

void Beer::writeToStream(ostream & os)
{
	if (name == "#") {
		os << "Beer : This element wasn't set\n";
	}
	else {
		os << "Beer : " << (const Alcohol&)*this << " Type of Beer: " << toString(type) <<
			" Bitternes: " << bitterness << "\n";
	}
}

ostream & operator<<(ostream & os, const Beer & b)
{
	if (b.name == "#") {
		os << "Beer : This element wasn't set\n";
	}
	else {
		os << "Beer : " << (const Alcohol&)b << " Type of Beer: " << toString(b.type) << " Bitternes: " << b.bitterness << "\n";
	}
	return os;
}
