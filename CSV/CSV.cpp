#include "CSV.hpp"

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::getline;
using std::endl;

CSV::CSV(){
	items = vector<string>();
}

CSV::CSV(string filename){
	items = vector<string>();
	read(filename); 
}

//Take the items colSize at a time(allows for multiple ways top parse a file just in case
vector<vector<string>> CSV::parseItem(int colSize){
	if(colSize == 0)return vector<vector<string>>();
	vector<vector<string>> result = vector<vector<string>>();
	for(int i = 0;i < items.size();i++){
		if(i%colSize == 0){
			result.push_back(vector<string>()); //make sure the place of insert exists
		}
		result[i/colSize].push_back(items[i]); //put them in the proper slots
	}
	return result;
}

void CSV::addItem(string str){
	items.push_back(str);
}

//file I/O
bool CSV::read(string filename){
	ifstream fin;
	fin.open(filename);
	if(fin){
		while(!fin.eof()){
			string line = '';
			getline(fin,line);
			vector<string> itemSplit = split(line);
			for(int i = 0;i < itemSplit.size();i++){
				items.push_back(itemSplit[i]);
			}
		}
		fin.close();
	}
}

bool CSV::write(string filename){
	ofstream fout;
	fout.open(filename);
	if(fout){
		while(!fout.eof()){
			fout << join(items) << endl;
		}
		fout.close();
	}
	
}

vector<string> CSV::split(string str, char sep){
	vector<string> strs = vector<string>();
	string temp = '';
	for(int i = 0;i < str.length();i++){
		if(str[i]==',' && temp != ''){
			strs.push_back(temp);
		}
		else if(str[i] != ','){
			temp.push_back(str[i]);
		}
	}
	return strs;
}

string CSV::join(vector<string> str, char sep){
	string result = '';
	for(int i = 0;i < str.length();i++){
		result.append(str[i]);
		if(i != str.length()-1){
			result.push_back(sep);
		}
	}
	return result;
}
