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
	vector<vector<string>> courses;
	while(getline(file, line)){
		string temp = line;
		string temp1;
		stringstream s(temp);
		while(s >> temp1){
			reqLine.push_back(temp1);
		}
	/*	vector<string>::iterator iter;
		for(iter = reqLine.begin(); iter != reqLine.end(); iter++){
			cout << *iter << " ";
		}
		cout << endl << endl;*/
		myRequirements -> setCourses(reqLine);
		if (reqLine[0] == "COURSE" && reqLine.size() > 3){
		//	cout << "w" << endl;
			courses.push_back(reqLine);
		}

		reqLine.clear();
	}
	vector<vector<string>>:: iterator iter;
	for (iter = courses.begin(); iter != courses.end(); iter++){
		myRequirements -> addReqs(*iter);
	}
	myRequirements -> printAdjVec();

}

requirements* requirementsParser::getRequirements(){
	return myRequirements;
}
