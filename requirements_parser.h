#define REQUIREMENTS_PARSER_H
#ifndef REQUIREMENTS_PARSER_H
#include "Requirements.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
class RequirementsParser{
	public:
		RequirementsParser(string file);

	private:
		vector<Requirements*> reqVec;
};


#endif
