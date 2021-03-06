/*File: Util.cpp
*Author: Michael Huelsman
*Notes:
*Problems:
*Project:
* Dish Based Reasoning
*/

#include "Util.hpp"

vector<string> intersection(vector<string> one, vector<string> two){
	vector<string> result = vector<string>();
	for(int i = 0 ;i < one.size();i++){
		for(int j = 0;j < two.size();j++){
			if(one[i] == two[j]){
				result.push_back(one[i]);
				break;
			}
		}
	}
	return unique(result);
}

vector<string> setUnion(vector<string> one, vector<string> two){
	vector<string> result = one;
	for(int i = 0;i < two.size();i++){
		result.push_back(two[i]);
	}
	return unique(result);
}

vector<string> unique(vector<string> set){
	vector<string> result = vector<string>();
	for(int i = 0;i < set.size();i++){
		bool add = true;
		for(int j = i+1;j < set.size();j++){
			if(set[i] == set[j])add = false;
		}
		if(add)result.push_back(set[i]);
	}
	return result;
}

vector<string> split(string str, char sep){
	vector<string> strs = vector<string>();
	string temp = "";
	for(int i = 0;i < str.length();i++){
		if(str[i]==',' && temp != ""){
			strs.push_back(temp);
			temp = "";
		}
		else if(str[i] != ','){
			temp.push_back(str[i]);
		}
	}
	if(temp != ""){
		strs.push_back(temp);
	}
	return strs;
}
