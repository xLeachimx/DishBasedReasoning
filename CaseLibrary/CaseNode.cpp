/*File: CaseNode.cpp
*Author: Michael Huelsman
*Notes:
*Problems:
*Project:
* Dish Based Reasoning
*/

#include "CaseNode.hpp"

//constructor
CaseNode::CaseNode(){
	similarity = 0;
	subject = Case();
}

CaseNode::CaseNode(Case c, int sim){
	similarity = sim;
	subject = c;
}

//accessors
Case CaseNode::getCase(){
	return subject;
}

int CaseNode::getSimilarity(){
	return similarity;
}

//comparitives
bool CaseNode::operator==(const CaseNode &comp){
	return similarity == comp.similarity;
}

bool CaseNode::operator>(const CaseNode &comp){
	return similarity > comp.similarity;
}

bool CaseNode::operator<(const CaseNode &comp){
	return similarity < comp.similarity;
}

bool CaseNode::operator>=(const CaseNode &comp){
	return similarity >= comp.similarity;
}

bool CaseNode::operator<=(const CaseNode &comp){
	return similarity <= comp.similarity;
}