#include <string>
#include <iostream>
#include "course.h"

using namespace std;

course:: course(){
}

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

string course:: getName(){
	return courseName;
}

string course:: getStatus(){
	return status;
}
