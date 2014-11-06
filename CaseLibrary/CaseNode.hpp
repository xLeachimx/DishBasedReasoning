/*File: CaseNode.cpp
*Author: Michael Huelsman
*Notes:
*Problems:
*Project:
* Dish Based Reasoning
*/

#ifndef CASENODE_HPP
#define CASENODE_HPP

#include "Case.hpp"

class CaseNode{
public:
	//constructor
	CaseNode();
	CaseNode(Case c, int sim);

	//accessors
	Case getCase();
	int getSimilarity();

	//comparitives
	bool operator==(const CaseNode &comp);
	bool operator>(const CaseNode &comp);
	bool operator<(const CaseNode &comp);
	bool operator>=(const CaseNode &comp);
	bool operator<=(const CaseNode &comp);
protected:
private:
	Case subject;
	int similarity;
};

#endif