/*File: Util.hpp
*Author: Michael Huelsman
*Notes:
*	Contains all utility functions needed for DBR
*Problems:
*Project:
* Dish Based Reasoning
*/

#ifndef UTIL_HPP
#define UTIL_HPP

#include <vector>
#include <string>
using std::vector;
using std::string;

vector<string> intersection(vector<string> one, vector<string> two);
vector<string> setUnion(vector<string> one, vector<string> two);
vector<string> unique(vector<string> set);

#endif