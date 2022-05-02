#pragma once
#include "Alcohol.h"
constexpr auto BEER_START_LINE = __LINE__;
enum class Type {
	BARLEY = 1,
	WHEAT,
	RYE,
	RICE,
	CORN
};
constexpr auto TYPE_COUNT = __LINE__ - BEER_START_LINE - 3;
const string TYPE_NAMES[] = { "BARLEY", "WHEAT", "RYE", "RICE", "CORN" };
const string BEER_MENU_STRING = "Choose type of beer (1 - BARLEY, 2 - WHEAT, 3 - RYE, 4 - RICE, 5 - CORN): ";
class Beer :
	public Alcohol
{
protected:
	Type type;
	int bitterness;
	void dummy() {};  // убираем абстрактность
	void readBeerFromConsole(istream& is, ostream& os);
public:
	Beer(string aName, double aDegree, double aPrice, Type aType, int aBitterness);
	Beer();
	void setType(Type aType);
	Type getType() const;
	void setBitterness(int aBitterness);
	int getBitterness() const;
	friend ostream& operator << (ostream& os, const Beer& b);
	void readFromConsole(istream& is, ostream& os) override;
	void writeToStream(ostream& os) override;

};

