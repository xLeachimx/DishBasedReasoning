/*File: CaseLibrary.cpp
*Author: Michael Huelsman
*Notes:
*Problems:
*Project:
* Dish Based Reasoning
*/

#include <algorithm>
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
		CaseNode temp = CaseNode(cases[i], c.similarity(cases[i]));
		result.push_back(temp);
	}
	sort(temp);
	return result;
}

Dish CaseLibrary::querySol(Case C){
	int highest = -1;
	int highLoc = -1;
	for(int i = 0;i < cases.size();i++){
		int temp = c.similarity(cases[i]);
		if(temp > highest){
			highest = temp;
			highLoc = i;
		}
	}
	if(highLoc == -1){
	}
	return cases[highLoc].getSolution();
}