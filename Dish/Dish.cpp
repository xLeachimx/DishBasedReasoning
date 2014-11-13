/*File: Dish.cpp
*Author: Michael Huelsman
*Notes:
*Problems:
*Project:
* Dish Based Reasoning
*/

#include "Dish.hpp"
#include "Util.hpp"
#include "Case.hpp"

//constructors
Dish::Dish(){
	name = "";
	attributes = vector<string>();
}

Dish::Dish(string n, vector<string> attr){
	name = n;
	attributes = attr;
}

//accessors
vector<string> Dish::getAttributes(){
	return attributes;
}

string Dish::getName(){
	return name;
}

string Dish::toString(){
	string result = name;
	result += ',';
	for(int i = 0;i < likes.size();i++){
		result += likes[i];
		if(i != likes.size()-1)result += ',';
	}
	return result;
}

//comparisons
double Dish::similarity(Dish comp){
	return (2*(intersection(attributes, comp.getAttributes()))) / (attributes.size()+comp.getAttributes().size());
}

int similarity(Case comp){
	return (intersection(attributes, comp.getLikes()) - intersection(attributes, comp.getDislikes()));
}

bool Dish::operator==(const string &comp){
	return name == comp;
}