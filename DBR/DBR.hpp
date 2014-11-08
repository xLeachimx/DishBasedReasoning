/*File: DBR.hpp
*Author: Michael Huelsman
*Notes:
*Problems:
*Project:
* Dish Based Reasoning
*/

#ifndef DBR_HPP
#define DBR_HPP

#include <string>
using std::string;

#include "Case.hpp"
#include "Dish.hpp"
#include "DishLibrary.hpp"
#include "CaseLibrary.hpp"

class DBR{
public:
	//constructors
	DBR();
	DBR(string caseFile, string dishFile);

	//backup initialization
	void init(string caseFile, string dishFile);

	void addCase(string casefile, Dish solution);

	Dish query(string filename);

	bool save(string caseFile, string dishFile);
protected:
	void parseDishLibFile(string filename);
	void parseCaseLibFile(string filename);
	Case parseCaseFile(string filename);
private:
	DishLibrary dishLib;
	CaseLibrary caseLib;
};

#endif