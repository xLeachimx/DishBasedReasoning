/*File: Dish.cpp
*Author: Michael Huelsman
*Notes:
*Problems:
*Project:
* Dish Based Reasoning
*/

#include "Dish.hpp"
#include "Util.hpp"

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

//comparisons
double Dish::similarity(Dish comp){
	return (2*(intersection(attributes, comp.getAttributes()))) / (attributes.size()+comp.getAttributes().size());
}

bool Dish::operator==(const Dish &copy){
	return name == copy.name;
}