#ifndef REQUIREMENTSPARSER_H
#define REQUIREMENTSPARSER_H
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "requirementsObj.h"

using namespace std;

class requirementsParser{
	public:
		void deleteAll();
		requirementsParser(string fileName);
		requirements *getRequirements();
	private:
		requirements *myRequirements;
};

#endif
