#include "requirements_parser.h"
#include "Requirements.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <vector>

using namespace std;

RequirementsParser::RequirementsParser(string myFile){
	bool exists = false;
	struct stat b;
	exists = (stat(myFile.c_str(), &b) == 0);
	if(exists){
		ifstream file(myFile);
		string str;
		while(getline(file, str)){
			Requirements* line = new Requirements();
			reqVec.push_back(line -> parser(str));
		}
	}
	else{
		cout << "File " << myFile << " could not be found!" << endl;
	}
}
