#include <string>
#include <iostream>

using namespace std;

course:: course(string n, string s){
	courseName = n;
	status = s;
}

void course:: setName(string n){
	courseName = n;
}

void course:: setStatus(string s){
	status = s;
}

string getName(){
	return courseName;
}

string getStatus(){
	return status;
}
