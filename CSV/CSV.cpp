#include "CSV.hpp"

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::getline;
using std::endl;

CSV::CSV(){
	items = vector<vector<string> >();
}

CSV::CSV(string filename){
	items = vector<vector<string> >();
	read(filename); 
}

vector<vector<string> > CSV::getItems(){
	return items;
}

//file I/O
bool CSV::read(string filename){
	ifstream fin;
	fin.open(filename);
	if(fin){
		while(!fin.eof()){
			string line = "";
			getline(fin,line);
			vector<string> itemSplit = split(line);
			items.push_back(itemSplit);
		}
		fin.close();
		return true;
	}
	return false;
}

bool CSV::write(string filename){
	ofstream fout;
	fout.open(filename);
	if(fout){
		while(!fout.eof()){
			for(int i = 0;i < items.size();i++){
				fout << join(items[i]) << endl;
			}
		}
		fout.close();
		return true;
	}
	return false;
	
}

vector<string> CSV::split(string str, char sep){
	vector<string> strs = vector<string>();
	string temp = "";
	for(int i = 0;i < str.length();i++){
		if(str[i]==',' && temp != ""){
			strs.push_back(temp);
		}
		else if(str[i] != ','){
			temp.push_back(str[i]);
		}
	}
	return strs;
}

string CSV::join(vector<string> strs, char sep){
	string result = "";
	for(int i = 0;i < strs.size();i++){
		result.append(strs[i]);
		if(i != strs.size()-1){
			result.push_back(sep);
		}
	}
	return result;
}
