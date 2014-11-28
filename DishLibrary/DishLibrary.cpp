/*File: DishLibrary.cpp
*Author: Michael Huelsman
*Notes:
*Problems:
*Project:
* Dish Based Reasoning
*/

#include "DishLibrary.hpp"

//constructor
DishLibrary::DishLibrary(){
	dishes = vector<Dish>();
}

DishLibrary::DishLibrary(vector<Dish> fare){
	dishes = fare;
}

//accessors
vector<Dish> DishLibrary::getDishes(){
	return dishes;
}

//mutators
bool DishLibrary::addDish(Dish add){ //returns false if already exists
	dishes.push_back(add);
	return true;
}

//queries
bool DishLibrary::isDish(string name){
	for(int i = 0;i < dishes.size();i++){
		if(dishes[i] == name){
			return true;
		}
	}
	return false;
}

Dish DishLibrary::getDish(string name){
	int loc = findDish(name);
	if(loc == -1)return Dish("Not found", vector<string>());
	return dishes[findDish(name)];
}

int DishLibrary::findDish(string name){
	for(int i = 0;i < dishes.size();i++){
		if(dishes[i] == name){
			return i;
		}
	}
	return -1;
}

Dish DishLibrary::query(Dish comp){
	double highest = 0.0;
	int highLoc = -1;
	for(int i = 0;i < dishes.size();i++){
		double temp = dishes[i].similarity(comp);
		if(temp > highest){
			highest = temp;
			highLoc = i;
		}
	}
	if(highLoc == -1)return Dish();
	return dishes[highLoc];
}

Dish DishLibrary::query(Case comp){
	double highest = 0.0;
	int highLoc = -1;
	for(int i = 0;i < dishes.size();i++){
		double temp = dishes[i].similarity(comp);
		if(temp > highest){
			highest = temp;
			highLoc = i;
		}
	}
	if(highLoc == -1)return Dish();
	return dishes[highLoc];
}

//operators
Dish &DishLibrary::operator[](const int index){
	return dishes[index];
}