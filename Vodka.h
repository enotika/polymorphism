#pragma once
#include "Alcohol.h"
constexpr auto START_VODKA_LINE = __LINE__;
enum class �lassification {
	ECONOMY = 1,
	STANDARD,
	PREMIUM,
	SUPER_PREMIUM,
	ULTRA_PREMIUM
};
constexpr auto CLASS_COUNT = __LINE__ - START_VODKA_LINE - 3;
const string VODKA_CLASS_NAMES[] = { "ECONOMY", "STANDARD", "PREMIUM", "SUPER_PREMIUM", "ULTRA_PREMIUM" };
const string VODKA_STRING = "Choose class of vodka (1 - ECONOMY, 2 - STANDARD, 3 - PREMIUM, 4 - SUPER_PREMIUM, 5 - ULTRA_PREMIUM): ";
class Vodka :
	public Alcohol
{
protected:
	�lassification classification;
	void readVodkaFromConsole(istream & is, ostream & os);
	void dummy() {};  // ������� �������������
public:
	Vodka(string aName, double aDegree, double aPrice, �lassification aClassification);
	Vodka();
	void set�lassification(�lassification a�lassification);
	�lassification get�lassification() const;
	friend ostream& operator << (ostream& os, const Vodka& b);
	void readFromConsole(istream & is, ostream & os) override;
	void writeToStream(ostream& os) override;

};

