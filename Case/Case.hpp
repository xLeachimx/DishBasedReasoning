/*File: Case.hpp
*Author: Michael Huelsman
*Notes:
*	The higher the integer the greater the similarity
*Problems:
*Project:
*	Dish Based Reasoning
*/

#ifndef CASE_HPP
#define CASE_HPP

#include <vector>
#include <string>
using std::vector;
using std::string;

#include "Dish.hpp"

class Case{
public:
	//constructors
	Case();
	Case(vector<string> like, vector<string> dislike, Dish &sol);

	//accessors
	vector<string> getLikes();
	vector<string> getDislikes();
	Dish getSolution();
	string toString();

	//comparison
	double similarity(Case comp);
protected:
private:
	vector<string> likes;
	vector<string> dislikes;
	Dish solution;
};

#endif