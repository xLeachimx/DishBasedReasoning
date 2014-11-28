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
	for(int i = 0;i < attributes.size();i++){
		result += attributes[i];
		if(i != attributes.size()-1)result += ',';
	}
	return result;
}

//comparisons
double Dish::similarity(Dish comp){
	double numerator = intersection(attributes, comp.getAttributes()).size();
	double denominator = setUnion(attributes, comp.getAttributes()).size();
	return numerator/denominator;
}

double Dish::similarity(Case comp){
	double numerator = intersection(attributes, comp.getLikes()).size() - intersection(attributes, comp.getDislikes()).size();
	double denominator = setUnion(attributes, comp.getLikes()).size();
	return numerator/denominator;
}

bool Dish::operator==(const string &comp){
	return name == comp;
}