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
/*	else if(arr[0] == "COURSE"){
		
	}*/
	else{
		cout << "HI" << endl;
	}
}

void requirements:: findLL(vector<string> vec){
	int size = vec.size();
	courseLL *newCLL = new courseLL;
	vector<string>::iterator iter;
	
	if (size > 3){
		cout << "e" << endl;
	}
	else{

	}
}

void requirements:: setTotal(int n){
	total = n;
}

int requirements:: getTotal(){
	return total;
}
