#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sys/stat.h>
#include "offeringsParser.h"
#include "plannedObj.h"

using namespace std;

int main(int argc, char **argv){
	if(argc != 4){
		cout << "Please run the program as follows: ./schedule.exe <Requirements File> <Offerings File> <Planned Schedule File>" << endl;
	}else{
		
		bool exists = false;
		struct stat b;
		string fileName;
		for(int i = 1; i < 4; i++){
			fileName = argv[i];
			exists = (stat(fileName.c_str(), &b) == 0);
			if(!exists){
				cout << "File " << fileName << " could not be found!" << endl;
				exit(0);
			}
		}

		unordered_map<string, offerings*> offersMap;
		offeringsParser *offers = new offeringsParser(argv[2]);
		offersMap = offers -> getMap();
		
		auto search = offersMap.find("AN301");
		if(search != offersMap.end()){
			cout << "Found " << search -> first << " : " << search -> second -> getCredits();
		}

		vector<string> plannedTest;
		vector<string>::iterator iter;
		planned *plan = new planned(argv[3]);
		plannedTest = plan -> getF19();
		cout << endl << endl;

		for(iter = plannedTest.begin(); iter != plannedTest.end(); iter++){
			cout << *iter << ", "; 
		}
		cout << endl;
		
	}
	return 0;
}
