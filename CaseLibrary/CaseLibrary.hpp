/*File: CaseLibrary.hpp
*Author: Michael Huelsman
*Notes:
*	Empty dish has a name of ""
*Problems:
*Project:
* Dish Based Reasoning
*/

#ifndef CASELIBRARY_HPP
#define CASELIBRARY_HPP

#include <vector>
#include <string>
using std::vector;
using std::string;

#include "CaseNode.hpp" //to be implemented

class CaseLibrary{
public:
	//constructor
	CaseLibrary();
	CaseLibrary(vector<Case> lib);

	//accessors
	vector<Case> getCases();

	//mutators
	void addCase(Case c);

	//queries
	vector<CaseNode> queryList(Case c);//gets all similar cases
	Dish querySol(Case C);
protected:
private:
	vector<Case> cases;
};

#endif