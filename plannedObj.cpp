#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <sys/stat.h>
#include "plannedObj.h"

using namespace std;

planned::planned(string fileName){
	int state, i, counter;
	state = i = counter = 0;
	ifstream file(fileName);
	string line;
	unordered_map<int, int> dict;
	while(getline(file, line)){
		/* If it ends in 0, it's a fall semester */
		if(line.substr(0, 1) == "F"){
			dict.insert(make_pair(i, stoi(line.substr(1, 4).append("1"))));
		}
		/* If it ends in 1, it's a spring semester */
		else{
			dict.insert(make_pair(i, stoi(line.substr(1, 4).append("0"))));
		}
		i++;
	}
	if(i == 8){
		file.clear();
		file.seekg(0);
		vector<int> dont_check;
		int num = -1;
		int minimum = 99999;
		while(dont_check.size() != 8){
			for(i = 0; i < 8; i++){
				if(dict[i] < minimum && !(find(dont_check.begin(), dont_check.end(), i) != dont_check.end())){
					minimum = dict[i];
					num = i;
				}
			}
			dont_check.push_back(num);
			num = -1;
			minimum = 99999;
		}
		bool error = true;
		for(int j = 1; j < dont_check.size(); j++){
			if(dont_check[j] == dont_check[j-1]){
				error = false;
				cout << "ERROR: You must have exactly 8 semesters without any repeats!" << endl;
				break;
			}
		}
		if(error){
			i = 0;
			while(getline(file, line)){
				if(i == dont_check[counter]){
					if(counter == 0){
						addSem1(line);
					}
					else if(counter == 1){
						addSem2(line);
					}
					else if(counter == 2){
						addSem3(line);
					}
					else if(counter == 3){
						addSem4(line);
					}
					else if(counter == 4){
						addSem5(line);
					}
					else if(counter == 5){
						addSem6(line);
					}
					else if(counter == 6){
						addSem7(line);
					}
					else if(counter == 7){
						addSem8(line);
					}
					counter++;
					i = 0;
					file.clear();
					file.seekg(0);
				}
				else{
					i++;
				}
			}
			valid(true);
		}else{
			valid(false);
		}
	}else{
		cout << "ERROR: You must have exactly 8 semesters without any repeats!" << endl;
		valid(false);
	}
}
void planned::valid(bool isValid){
	validity = isValid;
}

bool planned::getValid(){
	return validity;
}

void planned::addSem1(string Sem1){
	string temp = Sem1;
	string temp1;
	stringstream s(temp);
	while(s >> temp1){
		sem1.push_back(temp1);
	}
}

vector<string> planned::getSem1(){
	return sem1;
}

void planned::addSem2(string Sem2){
	string temp = Sem2;
	string temp1;
	stringstream s(temp);
	while(s >> temp1){
		sem2.push_back(temp1);
	}
}

vector<string> planned::getSem2(){
	return sem2;
}

void planned::addSem3(string Sem3){
	string temp = Sem3;
	string temp1;
	stringstream s(temp);
	while(s >> temp1){
		sem3.push_back(temp1);
	}
}

vector<string> planned::getSem3(){
	return sem3;
}

void planned::addSem4(string Sem4){
	string temp = Sem4;
	string temp1;
	stringstream s(temp);
	while(s >> temp1){
		sem4.push_back(temp1);
	}
}

vector<string> planned::getSem4(){
	return sem4;
}

void planned::addSem5(string Sem5){
	string temp = Sem5;
	string temp1;
	stringstream s(temp);
	while(s >> temp1){
		sem5.push_back(temp1);
	}
}

vector<string> planned::getSem5(){
	return sem5;
}

void planned::addSem6(string Sem6){
	string temp = Sem6;
	string temp1;
	stringstream s(temp);
	while(s >> temp1){
		sem6.push_back(temp1);
	}
}

vector<string> planned::getSem6(){
	return sem6;
}

void planned::addSem7(string Sem7){
	string temp = Sem7;
	string temp1;
	stringstream s(temp);
	while(s >> temp1){
		sem7.push_back(temp1);
	}
}

vector<string> planned::getSem7(){
	return sem7;
}

void planned::addSem8(string Sem8){
	string temp = Sem8;
	string temp1;
	stringstream s(temp);
	while(s >> temp1){
		sem8.push_back(temp1);
	}

}

vector<string> planned::getSem8(){
	return sem8;
}
