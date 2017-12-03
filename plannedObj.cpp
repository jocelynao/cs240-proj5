#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <sys/stat.h>
#include "plannedObj.h"

using namespace std;

planned::planned(string fileName){
	int state = 0;
	ifstream file(fileName);
	string line;
	while(getline(file, line)){
		if(state == 0){
			addF16(line);
		}
		else if(state == 1){
			addS17(line);
		}
		else if(state == 2){
			addF17(line);
		}
		else if(state == 3){
			addS18(line);
		}
		else if(state == 4){
			addF18(line);
		}
		else if(state == 5){
			addS19(line);
		}
		else if(state == 6){
			addF19(line);
		}			
		else if(state == 7){
			addS20(line);
		}
		state++;
	}
}

void planned::addF16(string F16){
	string temp = F16;
	string temp1;
	stringstream s(temp);
	while(s >> temp1){
		F2016.push_back(temp1);
	}
}

vector<string> planned::getF16(){
	return F2016;
}

void planned::addS17(string S17){
	string temp = S17;
	string temp1;
	stringstream s(temp);
	while(s >> temp1){
		S2017.push_back(temp1);
	}
}

vector<string> planned::getS17(){
	return S2017;
}

void planned::addF17(string F17){
	string temp = F17;
	string temp1;
	stringstream s(temp);
	while(s >> temp1){
		F2017.push_back(temp1);
	}
}

vector<string> planned::getF17(){
	return F2017;
}

void planned::addS18(string S18){
	string temp = S18;
	string temp1;
	stringstream s(temp);
	while(s >> temp1){
		S2018.push_back(temp1);
	}
}

vector<string> planned::getS18(){
	return S2018;
}

void planned::addF18(string F18){
	string temp = F18;
	string temp1;
	stringstream s(temp);
	while(s >> temp1){
		F2018.push_back(temp1);
	}
}

vector<string> planned::getF18(){
	return F2018;
}

void planned::addS19(string S19){
	string temp = S19;
	string temp1;
	stringstream s(temp);
	while(s >> temp1){
		S2019.push_back(temp1);
	}
}

vector<string> planned::getS19(){
	return S2019;
}

void planned::addF19(string F19){
	string temp = F19;
	string temp1;
	stringstream s(temp);
	while(s >> temp1){
		F2019.push_back(temp1);
	}
}

vector<string> planned::getF19(){
	return F2019;
}

void planned::addS20(string S20){
	string temp = S20;
	string temp1;
	stringstream s(temp);
	while(s >> temp1){
		S2020.push_back(temp1);
	}

}

vector<string> planned::getS20(){
	return S2020;
}
