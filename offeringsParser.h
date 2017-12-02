#include <iostream>
#include <unordered_map>
#include "offeringsObj.h"


using namespace std;

class offeringsParser{
	public:
		offeringsParser(string fileName);
		unordered_map<string, offerings*> getMap();
	private:
		unordered_map<string, offerings*> offeringsMap;
};
