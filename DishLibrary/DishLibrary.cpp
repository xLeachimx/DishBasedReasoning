/*File: DishLibrary.cpp
*Author: Michael Huelsman
*Notes:
*Problems:
*Project:
* Dish Based Reasoning
*/

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

//operators
Dish &DishLibrary::operator[](const int index){
	return dishes[index];
}