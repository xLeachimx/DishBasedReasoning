/*File: main.cpp
*Author: Michael Huelsman
*Notes:
*	Interface
*	First command line arg is case file
*	Second command line arg is dish file
*Problems:
*Project:
*	Dish Based Reasoning
*/
#include "Dish.hpp"
#include "Case.hpp"
#include "DBR.hpp"

#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

int mainMenu();
Case constructProblem();
Dish constructDish();
bool goodSuggestion();

int main(int argc, char **argv){
	DBR reasoner = DBR(argv[1],argv[2]);
	int choice = 0;
	Case prob = Case();
	Dish sol = Dish();
	while((choice = mainMenu()) != 3){
		switch(choice){
			case 1:
				reasoner.addDish(constructDish());
				break;
			case 2:
				prob = constructProblem();
				sol = reasoner.query(prob);
				cout << "You should try ";
				cout << sol.getName() <<endl;
				if(goodSuggestion()){
					reasoner.addCase(Case(prob.getLikes(), prob.getDislikes(), sol));
				}
				break;
			default:
				cout << "Unrecognized input!" <<endl;
				break;
		}
	}
	cout << "Bye!" <<endl;
	reasoner.save(argv[1],argv[2]);
	return 0;
}

int mainMenu(){
	int choice = 0;
	cout << "1. Add Dish" <<endl;
	cout << "2. Get a Suggestion" <<endl;
	cout << "3. Done" <<endl;
	cin >> choice;
	return choice;
}

Case constructProblem(){
	string item = "";
	vector<string> wants = vector<string>();
	do{
		if(item != "")wants.push_back(item);
		cout << "Enter something you DO want(Enter end when done):" <<endl;
		cin >> item;
	}while(item != "end");
	vector<string> notWants = vector<string>();
	do{
		if(item != "")notWants.push_back(item);
		cout << "Enter something you DO NOT want(Enter end when done):" <<endl;
		cin >> item;
	}while(item != "end");
	return Case(wants, notWants, Dish());
}

Dish constructDish(){
	string item = "";
	string name = "";
	vector<string> attr = vector<string>();
	cout << "Name of the Dish:";
	cin >> name;
	do{
		if(item != "")attr.push_back(item);
		cout << "Enter an attribute of the dish(Enter end when done):";
		cin >> item;
	}while(item != "end");
	return Dish(name, attr);
}

bool goodSuggestion(){
	char ans = ' ';
	cout << "Did this help?(y/n):";
	cin >> ans;
	while(ans != 'y' && ans != 'n');
	if(ans == 'y')return true;
	return false;
}
