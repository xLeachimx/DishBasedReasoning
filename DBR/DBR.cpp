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
#include <iostream>
using std::cout;
using std::endl;
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
	fout.open(caseFile.c_str());
	if(!fout)return false;
	for(int i = 0;i < caseLib.getCases().size();i++){
		fout << caseLib.getCases()[i].toString() << '\n';
	}
	fout.close();
	fout.open(dishFile.c_str());
	if(!fout)return false;
	for(int i = 0;i < dishLib.getDishes().size();i++){
		fout << dishLib.getDishes()[i].toString() << '\n';
	}
	fout.close();
	return true;
}


//for parsing files
void DBR::parseDishLibFile(string filename){
	dishLib = DishLibrary();
	ifstream fin;
	fin.open(filename.c_str());
	if(!fin)return;
	string line = "";
	getline(fin, line);
	while(line != "" && !fin.eof()){
		vector<string> items = split(line, ',');
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
	fin.open(filename.c_str());
	if(!fin)return;
	string line = "";
	getline(fin, line);
	while(line != "" && !fin.eof()){
		vector<string> likes = split(line, ',');
		getline(fin, line);
		vector<string> dislikes = split(line, ',');
		getline(fin, line);
		cout << "Likes:" <<endl;
		for(int i = 0;i < likes.size();i++){
			cout << likes[i];
		}
		cout << endl;
		cout << "Dislikes: " <<endl;
		for(int i = 0;i < likes.size();i++){
			cout << likes[i];
		}
		cout << endl;
		cout << "Solution: " <<endl;
		for(int i = 0;i < likes.size();i++){
			cout << likes[i];
		}
		cout << endl;
		caseLib.addCase(Case(likes, dislikes, dishLib.getDish(line)));
		getline(fin, line);
	}
	fin.close();
}

Case DBR::parseCaseFile(string filename){
	caseLib = CaseLibrary();
	ifstream fin;
	fin.open(filename.c_str());
	if(!fin)return Case();
	string line = "";
	getline(fin, line);
	vector<string> likes = split(line, ',');
	getline(fin, line);
	vector<string> dislikes = split(line, ',');
	fin.close();
	return Case(likes, dislikes, Dish());
}
