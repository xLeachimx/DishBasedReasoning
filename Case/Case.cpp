/*File: Case.cpp
*Author: Michael Huelsman
*Notes:
*Problems:
*Project:
* Dish Based Reasoning
*/

#include "Case.hpp"
#include "Util.hpp"

//constructors
Case::Case(){
	likes = vector<string>();
	dislikes = vector<string>();
	solution = Dish();
}

Case::Case(vector<string> like, vector<string> dislike, Dish &sol){
	likes = like;
	dislikes = dislikes;
	solution = sol;
}


//accessors
vector<string> Case::getLikes(){
	return likes;
}

vector<string> Case::getDislikes(){
	return dislikes;
}

Dish Case::getSolution(){
	return solution;
}

string Case::toString(){
	string result = "";
	for(int i = 0;i < likes.size();i++){
		result += likes[i];
		if(i != likes.size()-1)result += ',';
	}
	result += '\n';
	for(int i = 0;i < dislikes.size();i++){
		result += dislikes[i];
		if(i != dislikes.size()-1)result += ',';
	}
	result += '\n';
	result += solution.getName();
	return result;
}

//comparison
int Case::similarity(Case comp){
	int positive = intersection(likes, comp.getLikes()).size() + intersection(dislikes, comp.getDislikes()).size();
	int negative = 0 - intersection(dislikes, comp.getLikes()).size() - intersection(likes, comp.getDislikes()).size();
	return potitive + negative;
}