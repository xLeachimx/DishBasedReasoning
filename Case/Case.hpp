/*File: Case.hpp
*Author: Michael Huelsman
*Notes:
*	THe higher the integer the greater the similarity
*Problems:
*	As of yet no Dish.hpp
*Project:
*	Dish Based Reasoning
*/

#ifndef CASE_HPP
#define CASE_HPP

#include <vector>
#include <string>
using std::vector;
using std::string;

#include "Dish.hpp" //to be made

class Case{
public:
	//constructors
	Case();
	Case(vector<string> like, vector<string> dislike, Dish &sol);

	//accessors
	vector<string> getLikes();
	vector<string> getDislikes();
	Dish getSolution();

	//comparison
	int similarity(Case comp);
protected:
private:
	vector<string> likes;
	vector<string> dislikes;
	Dish solution;
};

#endif