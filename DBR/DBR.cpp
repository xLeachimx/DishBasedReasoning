/*File: DBR.cpp
*Author: Michael Huelsman
*Notes:
*Problems:
*Project:
* Dish Based Reasoning
*/

#include "DBR.hpp"
#include "CaseNode.hpp"
#include "Util.hpp"

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::getline;

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
		solution = dishLib.query(problem);
	}
	return solution;
}

Dish DBR::query(Case problem){
	Dish solution = caseLib.querySol(problem);
	if(solution.getName() == ""){
		solution = dishLib.query(problem);
	}
	return solution;
}

bool DBR::save(string caseFile, string dishFile){
	ofstream fout;
	fout.open(caseFile);
	if(!fout)return false;
	for(int i = 0;i < caseLib.getCases().size();i++){
		cout << caseLib.getCases()[i].toString() <<endl;
		fout << caseLib.getCases()[i].toString() << '\n';
	}
	fout.close();
	fout.open(dishFile);
	if(!fout)return false;
	for(int i = 0;i < dishLib.getDishes().size();i++){
		cout << dishLib.getDishes()[i].toString() <<endl;
		fout << dishLib.getDishes()[i].toString() << '\n';
	}
	fout.close();
	return true;
}


//for parsing files
void DBR::parseDishLibFile(string filename){
	dishLib = DishLibrary();
	ifstream fin;
	fin.open(filename);
	if(!fin)return;
	string line = "";
	getline(fin, line);
	while(line != "" && !fin.eof()){
		vector<string> items = split(line, ',');
		for(int i = 0;i < items.size();i++){
			cout << items[i] <<endl;
		}
		string name = items[0];
		items[0] = items[items.size()-1];
		items.pop_back();
		dishLib.addDish(Dish(name, items));
		getline(fin, line);
	}
	fin.close();
}

void DBR::parseCaseLibFile(string filename){
	caseLib = CaseLibrary();
	ifstream fin;
	fin.open(filename);
	if(!fin)return;
	string line = "";
	getline(fin, line);
	while(line != "" && !fin.eof()){
		vector<string> likes = split(line, ',');
		getline(fin, line);
		vector<string> dislikes = split(line, ',');
		getline(fin, line);
		caseLib.addCase(Case(likes, dislikes, dishLib.getDish(line)));
		getline(fin, line);
	}
	fin.close();
}

Case DBR::parseCaseFile(string filename){
	caseLib = CaseLibrary();
	ifstream fin;
	fin.open(filename);
	if(!fin)return Case();
	string line = "";
	getline(fin, line);
	vector<string> likes = split(line, ',');
	getline(fin, line);
	vector<string> dislikes = split(line, ',');
	fin.close();
	return Case(likes, dislikes, Dish());
}