#ifndef REQUIREMENTS_H
#define REQUIREMENTS_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "credit.h"
#include "courseNode.h"
#include "chooseObj.h"

using namespace std;

class requirements{
	private:
		int total;
		vector<credit> creds;
		vector<node*> adjVecCourses;
		vector<node*> RCourses;
		vector<node*> MCourses;
		vector<choose*> chooseVec;
	public:
		void menu(vector<string> vec);
		void makeNode(vector<string> vec);
		void setCourses(vector<string> reqLine);
		void addReqs(vector<string> reqLine);
		void findReqs();
		void addOffs(vector<string> courseOffs);
		void addReqsOffs();
		void printAdjVec();
		bool alreadyIn(vector<string> reqLine);
		bool check(vector<string> semClasses);
		bool checkMandRs();
		void setTotal(int n);
		int getTotal();
		vector<credit> getCreds();
		vector<choose*> getChooseVec();	
		~requirements();
};

#endif
