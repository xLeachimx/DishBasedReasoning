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

Case::Case(vector<string> like, vector<string> dislike, Dish sol){
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
double Case::similarity(Case comp){
	vector<string> sameLikes = intersection(likes, comp.getLikes());
	vector<string> sameDislikes = intersection(dislikes, comp.getDislikes());
	vector<string> oppLikes = intersection(likes, comp.getDislikes());
	vector<string> oppDislikes = intersection(dislikes, comp.getLikes());
	vector<string> possibles = setUnion(setUnion(likes, dislikes), setUnion(comp.getLikes(), comp.getDislikes()));
	double numerator = (sameLikes.size() + sameDislikes.size()) - (oppLikes.size() + oppDislikes.size());
	double denominator = possibles.size();
	return numerator/denominator;
}