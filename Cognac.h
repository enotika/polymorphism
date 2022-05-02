#pragma once
#include "Alcohol.h"
class Cognac :
	public Alcohol
{
protected:
	int score;
	string country;
	void readCognacFromConsole(istream & is, ostream & os);
	void dummy() {};  // убираем абстрактность
public:
	void setScore(int aScore);
	int getScore() const;
	void setCountry(string aCountry);
	string getCountry() const;
	Cognac();
	Cognac(string aName, double aDegree, double aPrice, int aScore, string aCountry);
	friend ostream& operator << (ostream& os, const Cognac& b);
	void readFromConsole(istream & is, ostream & os) override;
	void writeToStream(ostream& os) override;

};

