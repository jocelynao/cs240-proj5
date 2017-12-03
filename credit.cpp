#include <string>
#include <iostream>

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

void getName(){
	return credName;
}

void getNum(){
	return credNum;
}
