#ifndef PLANNEDOBJ_H
#define PLANNEDOBJ_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class planned{
	public:
		void valid(bool isValid);
		bool getValid();
		planned(string myFile);
		void addSem1(string Sem1);
		vector<string> getSem1();		
		void addSem2(string Sem2);
		vector<string> getSem2();
		void addSem3(string Sem3);
		vector<string> getSem3();
		void addSem4(string Sem4);
		vector<string> getSem4();
		void addSem5(string Sem5);
		vector<string> getSem5();
		void addSem6(string Sem6);
		vector<string> getSem6();
		void addSem7(string Sem7);
		vector<string> getSem7();
		void addSem8(string Sem8);
		vector<string> getSem8();
	private:
		bool validity;
		vector<string> sem1 = {"F"};
		vector<string> sem2 = {"S"};
		vector<string> sem3 = {"F"};
		vector<string> sem4 = {"S"};
		vector<string> sem5 = {"F"};
		vector<string> sem6 = {"S"};
		vector<string> sem7 = {"F"};
		vector<string> sem8 = {"S"};
};
#endif
