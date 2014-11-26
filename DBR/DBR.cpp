/*File: DBR.cpp
*Author: Michael Huelsman
*Notes:
*Problems:
*Project:
* Dish Based Reasoning
*/

#include "DBR.hpp"
#include "CaseNode.hpp"
#include "CSV.hpp"

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

void DBR::addCase(Case add){
	caseLib.addCase(add);
}

void DBR::addDish(Dish add){
	dishLib.addDish(add);
}

Dish DBR::query(string filename){
	Case problem = parseCaseFile(filename);
	Dish solution = caseLib.querySol(problem);
	if(solution.getName() == ""){
		solution = DishLibrary.query(problem);
	}
	return solution;
}

Dish DBR::query(Case problem){
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
	CSV dishLibfile = CSV(filename);
	vector<vector<string>> dishes = dishLibfile.getItems();
	dishLib = DishLibrary(vvToDishes(dishes)):
}

void DBR::parseCaseLibFile(string filename){
	CSV caseLibFile = CSV(filename);
	vector<vector<string>> cases = caseLibFile.getItems();
	caseLib = CaseLibrary(vvToCases(cases));
}

Case DBR::parseCaseFile(string filename){
	CSV casefile = CSV(filename);
	vector<vector<string>> temp = casefile.getItems();
	return vvToCases(temp)[0];
}

//convertors
vector<Dish> DBR::vvToDishes(vector<vector<string>> items){
	vector<Dish> result = vector<Dish>();
	for(int i = 0;i < items.size();i++){
		string name = items[i][0];
		//remove the name element as an attribute
		items[i][0] = items[i][items.size()-1];
		items[i].pop_back();
		result.push_back(Dish(name, items[i]));
	}
	return result;
}

vector<Case> DBR::vvToCases(vector<vector<string>> items){
	vector<Case> result = vector<Dish>();
	for(int i = 0;i < items.size();i+=3){
		vector<string> likes, dislikes;
		likes = items[i];
		dislikes = items[i+1]
		Dish solution = dishLib.getDish(items[i+2][0]);
		result.push_back(Case(likes, dislikes, solution));
	}
	return result;
}