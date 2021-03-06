/*File: CaseLibrary.cpp
*Author: Michael Huelsman
*Notes:
*Problems:
*Project:
* Dish Based Reasoning
*/

#include "CaseLibrary.hpp"

#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::sort;

//constructor
CaseLibrary::CaseLibrary(){
	cases = vector<Case>();
}

CaseLibrary::CaseLibrary(vector<Case> lib){
	cases = lib;
}

//accessors
vector<Case> CaseLibrary::getCases(){
	return cases;
}

//mutators
void CaseLibrary::addCase(Case c){
	cases.push_back(c);
}

//queries
vector<CaseNode> CaseLibrary::queryList(Case c){//gets all similar cases
	vector<CaseNode> result = vector<CaseNode>();
	for(int i = 0;i < cases.size();i++){
		if(c.similarity(cases[i]) > THRESHOLD){
			CaseNode temp = CaseNode(cases[i], c.similarity(cases[i]));
			result.push_back(temp);
		}
	}
	sort(result.begin(), result.end());
	return result;
}

Dish CaseLibrary::querySol(Case c){
	double highest = THRESHOLD;
	int highLoc = -1;
	for(int i = 0;i < cases.size();i++){
		double temp = c.similarity(cases[i]);
		cout << "Similarity:" <<endl;
		cout << temp <<endl;
		cout << "Name" <<endl;
		cout << cases[i].toString() <<endl;
		if(temp > THRESHOLD && temp > highest){
			highest = temp;
			highLoc = i;
		}
	}
	if(highLoc == -1){
		return Dish();
	}
	return cases[highLoc].getSolution();
}
