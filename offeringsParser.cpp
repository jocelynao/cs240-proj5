#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sys/stat.h>
#include <vector>
#include "offeringsObj.h"
#include "offeringsParser.h"
#include "requirementsObj.h"

using namespace std;

offeringsParser::offeringsParser(string fileName){
	ifstream file(fileName);
	string str;
	bool found;
	vector<string> addAdj;
	requirements myRequirements = new requirements();
	while(getline(file, str)){
		found = false;
		offerings *offered = new offerings(str);
		offeringsMap.insert(make_pair(offered -> getClass(), offered));	
		
		addAdj.push_back("COURSE");
		addAdj.push_back(offered -> getClass());
		addAdj.push_back("O");
		myRequirements -> setCourses(addAdj);
		addAdj.clear();
	}
	delete myRequirements;
}

unordered_map<string, offerings*> offeringsParser::getMap(){
	return offeringsMap;
}
