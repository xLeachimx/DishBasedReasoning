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

class Dish{
public:
	//constructors
	Dish();
	Dish(string n, vector<string> attributes);

	//accessors
	vector<string> getAttributes();
	string getName();

	//comparisons
	bool operator==(const Dish &copy)
protected:
private:
	string name;
	vector<string> attributes; 
};

#endif