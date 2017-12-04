#include <iostream>
#include <string>
#include <vector>
#include "requirementsObj.h"

using namespace std;

void requirements:: menu(vector<string> vec){
	if (vec[0] == "TOTAL"){
		setTotal(stoi(vec[1]));
	//	cout << getTotal() << endl;

	}
	else if(vec[0] == "CREDIT"){
		credit newCred(vec[1], stoi(vec[2]));
		creds.push_back(newCred);
	//	vector<credit>:: iterator cIter;
	/*	for (cIter = creds.begin(); cIter != creds.end(); cIter++){
			cout << cIter -> getName() << ", ";
		}
		cout << "\n" << endl;*/

	}
	else if(vec[0] == "COURSE"){
		insertLL(vec);		
	}
	else{
		cout << "HI" << endl;
	}
}

void requirements:: insertLL(vector<string> vec){
	courseLL *newCLL = new courseLL;
	vector<string>::iterator iter;
	int i = 0;
	for(iter = vec.begin(); iter != vec.end(); iter++){
		if(i != 0){
			if(i == 1){
				newCLL -> insert(vec[i], vec[i+1]);
			}else{
				if(i != 2){
					newCLL -> insert(vec[i], "");
				}
			}
		}
		i++;
	}
	cout << newCLL -> getHeadCourse() << endl;
}

void requirements:: printAdjVec(){
	vector<courseLL>:: iterator iter;
	for (iter = adjVecCourses.begin(); iter != adjVecCourses.end(); iter++){
		node *nodePtr = iter -> getHead();
		for (int i = 0; i < iter -> getLength(); i++){		
			cout << nodePtr -> courseObj.getName() << ", ";
		}
		cout << "\n" << endl;
	//	cout << iter -> getHead() << endl; 
	}
}

void requirements:: setTotal(int n){
	total = n;
}

int requirements:: getTotal(){
	return total;
}
