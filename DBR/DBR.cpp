/*File: DBR.cpp
*Author: Michael Huelsman
*Notes:
*Problems:
*Project:
* Dish Based Reasoning
*/

#include "DBR.hpp"
#include "CaseNode.hpp"

#include <fstream>
using std::ofstream;

//constructors
DBR::DBR(){
	dishLib = DishLibrary();
	caseLib = CaseLibrary();
}

DBR::DBR(string caseFile, string dishFile){
	parseDishLibFile(dishFile);
	parseCaseLibFile(caseFile);
}

//backup initialization
void DBR::init(string caseFile, string dishFile){
	parseDishLibFile(dishFile);
	parseCaseLibFile(caseFile);
}

//only for adding queries that come in
void DBR::addCase(string casefile, Dish solution){
	Case temp = parseCaseFile(casefile);
	temp = Case(temp.getLikes(), temp.getDislikes(), solution);
	caseLib.addCase(temp);
}

Dish DBR::query(string filename){
	Case problem = parseCaseFile(filename);
	Dish solution = caseLib.querySol(problem);
	if(solution.getName() == ""){
		solution = DishLibrary.query(problem);
	}
	return solution;
}

bool DBR::save(string caseFile, string dishFile){
	ofstream fout;
	fout.open(casefile);
	if(!fout)return false;
	for(int i = 0;i < caseLib.getCases().size();i++){
		fout << caseLib.getCases()[i].toString() << '\n';
	}
	fout.close();
	fout.open(dishfile);
	if(!fout)return false;
	for(int i = 0;i < dishLib.getDishes().size();i++){
		fout << dishLib.getDishes()[i].toString() << '\n';
	}
	fout.close();
	return true;
}


//for parsing files
void DBR::parseDishLibFile(string filename){
}

void DBR::parseCaseLibFile(string filename){
}

Case DBR::parseCaseFile(string filename){
}
