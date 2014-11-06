/*File: DishLibrary.hpp
*Author: Michael Huelsman
*Notes:
*Problems:
*Project:
* Dish Based Reasoning
*/

#ifndef DISHLIBRARY_HPP
#define DISHLIBRARY_HPP

#include <vector>
#include <string>
using std::vector;
using std:string;

#include "Dish.hpp"
#include "Case.hpp"

class DishLibrary{
public:
	//constructor
	DishLibrary();
	DishLibrary(vector<Dish> fare);

	//accessors
	vector<Dish> getDishes();

	//mutators
	bool addDish(Dish add); //returns false if already exists

	//queries
	bool isDish(string name);
	Dish getDish(string name);
	int findDish(string name);

	//similarities
	Dish mostSimilar(Dish comp);
	Dish mostSimilar(Case Comp);

	//operators
	Dish &operator[](const int index);
protected:
private:
	vector<Dish> dishes;
};

#endif