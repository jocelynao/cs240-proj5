#include "Requirements.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <vector>

using namespace std;

Requirements::Requirements(){
	head = NULL;
}

Requirements* Requirements::parser(string line){
	string array[10];
	int i = 0;
	for(i = 0; i < 10; i++){
		array[i] = "";
	}	
	i = 0;
	stringstream ssin(line);
	node *cursor = head;
	while(ssin.good() && i < 10 && array[i] != ""){
		ssin >> array[i];
		cursor -> keyWord = array[i];
		cursor = cursor -> next;
		i++;
	}
	return this;
}
