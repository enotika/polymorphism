#pragma once
#include "Alcohol.h"
constexpr auto START_WINE_LINE = __LINE__;
enum class WineType {
	SWEET = 1,
	SEMI_SWEET,
	DRY,
	SEMI_DRY,
	BRUT
};
constexpr auto WINE_TYPE_COUNT = __LINE__ - START_WINE_LINE - 3;
const string WINE_TYPE_NAMES[] = { "SWEET", "SEMI_SWEET", "DRY", "SEMI_DRY", "BRUT" };
const string WINE_MENU_STRING = "Choose type of wine (1 - SWEET, 2 - SEMI_SWEET, 3 - DRY, 4 - SEMI_DRY, 5 - BRUT): ";
class Wine :
	public Alcohol
{
protected:
	WineType wineType;
	void readWineFromConsole(istream & is, ostream & os);
	void dummy() {};  // убираем абстрактность
public:
	Wine(string aName, double aDegree, double aPrice, WineType aWineType);
	Wine();
	void setWineType(WineType aType);
	WineType getWineType() const;
	friend ostream& operator << (ostream& os, const Wine& b);
	void readFromConsole(istream & is, ostream & os) override;
	void writeToStream(ostream& os) override;
};

