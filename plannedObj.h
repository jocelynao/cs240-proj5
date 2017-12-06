#ifndef PLANNEDOBJ_H
#define PLANNEDOBJ_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class planned{
	public:
		planned(string myFile);
		void addF16(string F16);
		vector<string> getF16();		
		void addS17(string S17);
		vector<string> getS17();
		void addF17(string F17);
		vector<string> getF17();
		void addS18(string S18);
		vector<string> getS18();
		void addF18(string F18);
		vector<string> getF18();
		void addS19(string S19);
		vector<string> getS19();
		void addF19(string F19);
		vector<string> getF19();
		void addS20(string S20);
		vector<string> getS20();
	private:
		vector<string> F2016 = {"F"};
		vector<string> S2017 = {"S"};
		vector<string> F2017 = {"F"};
		vector<string> S2018 = {"S"};
		vector<string> F2018 = {"F"};
		vector<string> S2019 = {"S"};
		vector<string> F2019 = {"F"};
		vector<string> S2020 = {"S"};
};
#endif
