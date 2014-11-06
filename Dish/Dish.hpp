/*File: Dish.hpp
*Author: Michael Huelsman
*Notes:
*Problems:
*Project:
* Dish Based Reasoning
*/

#ifndef DISH_HPP
#define DISH_HPP

#include <vector>
#include <string>
using std::vector;
using std::string;

class Case;

class Dish{
public:
	//constructors
	Dish();
	Dish(string n, vector<string> attr);

	//accessors
	vector<string> getAttributes();
	string getName();

	//comparisons
	double similarity(Dish comp);
	int similarity(Case comp);

	bool operator==(const string &comp);
protected:
private:
	string name;
	vector<string> attributes; 
};

#endif