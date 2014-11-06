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

	Dish query(string filename);
protected:
private:
	DishLibrary dishLib;
	CaseLibrary caseLib;
};

#endif