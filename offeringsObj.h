#ifndef OFFERINGS_H
#define OFFERINGS_H
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class offerings{
	public:
		offerings(string line);
		void setClass(string setClass);
		string getClass();
		void setCredits(string setCredits);
		int getCredits();
		void setTerm(string setTerm);
		string getTerm();
		void setTags(string setTags);
		string getTags();
	private:
		string className = "";
		int credits = 0;
		string term = "";
		string tags = "";
};

#endif
