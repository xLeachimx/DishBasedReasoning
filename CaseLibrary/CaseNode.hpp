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
	CaseNode(Case c, double sim);

	//accessors
	Case getCase();
	double getSimilarity();

	//comparitives
	bool operator==(const CaseNode &comp);
	bool operator>(const CaseNode &comp);
	bool operator<(const CaseNode &comp);
	bool operator>=(const CaseNode &comp);
	bool operator<=(const CaseNode &comp);
protected:
private:
	Case subject;
	double similarity;
};

#endif