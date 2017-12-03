#include <iostream>
#include <string>
#include "courseLL.h"

node* courseLL:: getHead(){
	return &head;
}

void courseLL:: insert(string name, int num){	
	course newCourse(name, num);
	node newNode;
	newNode.course = newCourse;
	
	if (head == NULL){
		head = newNode;
		tail = newNode;
	}
	else{
		if (length == 1){
			head -> next = newNode;
		}
		newNode -> prev = tail;
		tail -> next = newNode;
		tail = newNode;
	}
	length = length + 1;	
}
