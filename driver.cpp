#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <unordered_map>
#include "offeringsParser.h"

using namespace std;

int main(int argc, char **argv){
	if(argc != 4){
		cout << "Please run the program as follows: ./schedule.exe <Requirements File> <Offerings File> <Planned Schedule File>" << endl;
	}else{
		unordered_map<string, offerings*> offersMap;
		offeringsParser *offers = new offeringsParser(argv[2]);
		offersMap = offers -> getMap();

		
		auto search = offersMap.find("AN301");
		if(search != offersMap.end()){
			cout << "Found " << search -> first << " : " << search -> second -> getCredits();
		}
	}
	return 0;
}
