#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sys/stat.h>
#include <vector>
#include "offeringsObj.h"
#include "offeringsParser.h"
#include "requirementsObj.h"

using namespace std;

offeringsParser::offeringsParser(string fileName, requirements *myRequirements){
	cout << "after initially adding" << endl;
	myRequirements -> printAdjVec();
	ifstream file(fileName);
	string str;
	bool found;
	vector<string> addAdj;
	while(getline(file, str)){
		found = false;
		offerings *offered = new offerings(str);
		offeringsMap.insert(make_pair(offered -> getClass(), offered));	
			
		addAdj.push_back("COURSE");
		addAdj.push_back(offered -> getClass());
		addAdj.push_back(offered -> getTags());
		
		myRequirements -> addOffs(addAdj);
		addAdj.clear();
	}
	cout << "Done with offerings file" << endl;
	myRequirements -> printAdjVec();
}

unordered_map<string, offerings*> offeringsParser::getMap(){
	return offeringsMap;
}
