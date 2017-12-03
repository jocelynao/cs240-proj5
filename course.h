#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>

using namespace std;

class course{
	private:
		string courseName = "";
		string status = "";
	public:
		course();	

		course(string n, string s);
		void setName(string n);
		void setStatus(string s);

		string getName();
		string getStatus();
};

#endif
