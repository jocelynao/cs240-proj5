#include <string>
#include <iostream>
#include "credit.h"

using namespace std;

credit::credit(string name, int num){
	credName = name;
	credNum = num;
}

void credit:: setName(string name){
	credName = name;
}

void credit:: setNum(int num){
	credNum = num;
}

string credit:: getName(){
	return credName;
}

int credit:: getNum(){
	return credNum;
}
