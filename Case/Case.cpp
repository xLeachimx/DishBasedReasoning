/*File: Case.cpp
*Author: Michael Huelsman
*Notes:
*Problems:
*Project:
* Dish Based Reasoning
*/

#include "Case.hpp"

//constructors
Case(){
	likes = vector<string>();
	dislikes = vector<string>();
	solution = Dish();
}

Case(vector<string> like, vector<string> dislike, Dish &sol){
	likes = like;
	dislikes = dislikes;
	solution = sol;
}


//accessors
vector<string> getLikes(){
	return likes;
}

vector<string> getDislikes(){
	return dislikes;
}

Dish getSolution(){
	return solution;
}


//comparison
int similarity(Case comp){
	int positive = intersection(likes, comp.getLikes()).size() + intersection(dislikes, comp.getDislikes()).size();
	int negative = 0 - intersection(dislikes, comp.getLikes()).size() - intersection(likes, comp.getDislikes()).size();
	return potitive + negative;
}

vector<string> intersection(vector<string> one, vector<string> two){
	vector<string> result = vector<string>();
	for(int i = 0 ;i < one.size();i++){
		for(int j = 0;j < two.size();j++){
			if(one[i] == two[i]){
				result.push_back(one[i]);
				break;
			}
		}
	}
	return result;
}