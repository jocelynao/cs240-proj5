#include <string>
#include <vector>
#include <iostream>
#include "chooseObj.h"

using namespace std;

choose::choose(vector<string> line){
	setAmount(stoi(line[1]));
	for(int i = 2; i < line.size(); i++){
		addClass(line[i]);
	}
}

void choose::addClass(string myClass){
	classes.push_back(myClass);
}


vector<string> choose::getClass(){
	return classes;
}

void choose::setAmount(int amt){
	amount = amt;
}

int choose::getAmount(){
	return amount;
}
