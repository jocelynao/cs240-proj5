#include <iostream>
#include <unordered_map>
#include "offeringsObj.h"
#include "requirementsObj.h"


using namespace std;

class offeringsParser{
	public:
		offeringsParser(string fileName, requirements *myRequirements);
		unordered_map<string, offerings*> getMap();
	private:
		unordered_map<string, offerings*> offeringsMap;
};
