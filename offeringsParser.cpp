#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sys/stat.h>
#include "offeringsObj.h"
#include "offeringsParser.h"

using namespace std;

offeringsParser::offeringsParser(string fileName){
	bool exists = false;
	struct stat b;
	exists = (stat(fileName.c_str(), &b) == 0);
	if(exists){
		ifstream file(fileName);
		string str;
		while(getline(file, str)){
			offerings *offered = new offerings(str);
			offeringsMap.insert(make_pair(offered -> getClass(), offered));	
		}
	}else{
		cout << "File " << fileName << " could not be found!" << endl;
		exit(0);
	}
}

unordered_map<string, offerings*> offeringsParser::getMap(){
	return offeringsMap;
}
