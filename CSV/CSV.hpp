/*FILE: SemanticNet.hpp
*Author: Michael Huelsman
*Notes:
* For doing read/write operations on a CSV
*Problems:
*
*/

#ifndef CSV_HPP
#define CSV_HPP

#include <vector>
#include <string>
using std::vector;
using std::string;

class CSV{
public:
	CSV();
	CSV(string filename);
	
	vector<vector<string>> parseItem(int colSize);
	
	void addItem(string str);
	
	//file I/O
	bool read(string filename);
	bool write(string filename);
	
protected:
	vector<string> split(string str, char sep = ',');
	string join(vector<string> str, char sep = ',');
private:
	vector<string> items;
};

#endif
