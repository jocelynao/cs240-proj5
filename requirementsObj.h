#ifndef REQUIREMENTS_H
#define REQUIREMENTS_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "credit.h"
#include "courseNode.h"

using namespace std;

class requirements{
	private:
		int total;
		vector<credit> creds;
		vector<node> adjVecCourses;
	public:
		void menu(vector<string> vec);
		void makeNode(vector<string> vec);
		void setCourses(vector<string> reqLine);
		void addReqs(vector<string> reqLine);
		void printAdjVec();

		void setTotal(int n);
		int getTotal();	
};

#endif
