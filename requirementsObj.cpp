#include <iostream>
#include <string>
#include <vector>
#include "requirementsObj.h"

using namespace std;

void requirements:: menu(vector<string> vec){
	if (vec[0] == "TOTAL"){
		setTotal(stoi(vec[1]));
		cout << getTotal() << endl;

	}
	else if(vec[0] == "CREDIT"){
		credit newCred(vec[1], stoi(vec[2]));
		creds.push_back(newCred);
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
	cout << newCLL -> getHead() << endl;
}

void requirements:: setTotal(int n){
	total = n;
}

int requirements:: getTotal(){
	return total;
}
