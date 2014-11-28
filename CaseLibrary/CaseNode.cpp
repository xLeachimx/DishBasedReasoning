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
	similarity = 0.0;
	subject = Case();
}

CaseNode::CaseNode(Case c, double sim){
	similarity = sim;
	subject = c;
}

//accessors
Case CaseNode::getCase(){
	return subject;
}

double CaseNode::getSimilarity(){
	return similarity;
}

//comparitives
bool CaseNode::operator==(const CaseNode &comp) const{
	return similarity == comp.similarity;
}

bool CaseNode::operator>(const CaseNode &comp) const{
	return similarity > comp.similarity;
}

bool CaseNode::operator<(const CaseNode &comp) const{
	return similarity < comp.similarity;
}

bool CaseNode::operator>=(const CaseNode &comp) const{
	return similarity >= comp.similarity;
}

bool CaseNode::operator<=(const CaseNode &comp) const{
	return similarity <= comp.similarity;
}