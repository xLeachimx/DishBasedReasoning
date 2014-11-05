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
			if(one[i] == two[i]){
				result.push_back(one[i]);
				break;
			}
		}
	}
	return result;
}