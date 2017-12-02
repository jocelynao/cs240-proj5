#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include "offeringsObj.h"

using namespace std;

offerings::offerings(string line){
	int i = 0;
	string array[4];
	stringstream ssin(line);
	array[0] = "";
	array[1] = "";
	array[2] = "";
	array[3] = "";
	while(ssin.good() && i < 4){
		ssin >> array[i];
		i++;
	}
	setClass(array[0]);
	setCredits(array[1]);
	setTerm(array[2]);
	setTags(array[3]);
}
void offerings::setClass(string setClass){
	className = setClass;
}

string offerings::getClass(){
	return className;
}

void offerings::setCredits(string setCredits){
	credits = stoi(setCredits);
}

int offerings::getCredits(){
	return credits;
}

void offerings::setTerm(string setTerm){
	term = setTerm;
}

string offerings::getTerm(){
	return term;
}

void offerings::setTags(string setTags){
	tags = setTags;
}

string offerings::getTags(){
	return tags;
}
