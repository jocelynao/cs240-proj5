#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include "requirementsObj.h"
#include "requirementsParser.h"

using namespace std;

requirementsParser::requirementsParser(string fileName){
	myRequirements = new requirements();
	ifstream file(fileName);
	string line;
	vector<string> reqLine;
	while(getline(file, line)){
		string temp = line;
		string temp1;
		stringstream s(temp);
		while(s >> temp1){
			reqLine.push_back(temp1);
		}
		myRequirements -> menu(reqLine);
		reqLine.clear()
	}

}

requirements getRequirements(){
	return myRequirements;
}
