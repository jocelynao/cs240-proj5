#ifndef REQUIREMENTS_H
#define REQUIREMENTS_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "credit.h"
#include "courseLL.h"

using namespace std;

class requirements{
	private:
		int total;
		vector<credit> creds;
		vector<courseLL> adjVecCourses;
	public:
		void menu(vector<string> vec);
		void insertLL(vector<string> vec);

		void setTotal(int n);
		int getTotal();	
};

#endif
