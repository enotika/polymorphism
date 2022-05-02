#include "Cognac.h"

void Cognac::readCognacFromConsole(istream & is, ostream & os)
{
	is.ignore();
	int t;
	os << "Enter score \n";
	while (true) {
		is >> t;
		try {
			setScore(t);
			break;
		}
		catch (exception&ex) {
			os << "Wrong input! Try again... " << ex.what() << endl;
		}
	}
	os << "Enter country\n";
	string s;
	is >> s;
	setCountry(s);
}

void Cognac::setScore(int aScore)
{
	if (aScore < 0 || aScore > 6) {
		throw exception("setScore: ivalid score(score must be between 0 and 6)");
	}
	score = aScore;
}

int Cognac::getScore() const
{
	return score;
}

void Cognac::setCountry(string aCountry)
{
	country = aCountry;
}

string Cognac::getCountry() const
{
	return country;
}

Cognac::Cognac()
{
	setName("#");
	setCountry("NoCountry");
	setDegree(0);
	setPrice(0);
	setScore(0);
}

Cognac::Cognac(string aName, double aDegree, double aPrice, int aScore, string aCountry) :
	Alcohol(aName, aDegree, aPrice)
{
	setScore(aScore);
	setCountry(aCountry);
}

void Cognac::readFromConsole(istream & is, ostream & os)
{
	Alcohol::readFromConsole(is, os);
	readCognacFromConsole(is, os);
}

void Cognac::writeToStream(ostream & os)
{
	if (name == "#") {
		os << "Cognac : This element wasn't set\n";
	}
	else {
		os << "Cognac: " << (const Alcohol&)*this << " Score: " << score << 
			" Country: " << country << "\n";
	}
}

ostream & operator<<(ostream & os, const Cognac & b)
{
	if (b.name == "#") {
		os << "Cognac : This element wasn't set\n";
	}
	else {
		os << "Cognac: " << (const Alcohol&)b << " Score: " << b.score << " Country: " << b.country << "\n";
	}
	return os;
}
