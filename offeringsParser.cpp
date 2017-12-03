#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sys/stat.h>
#include "offeringsObj.h"
#include "offeringsParser.h"

using namespace std;

offeringsParser::offeringsParser(string fileName){
	ifstream file(fileName);
	string str;
	while(getline(file, str)){
		offerings *offered = new offerings(str);
		offeringsMap.insert(make_pair(offered -> getClass(), offered));	
	}
}

unordered_map<string, offerings*> offeringsParser::getMap(){
	return offeringsMap;
}
