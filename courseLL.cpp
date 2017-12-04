#include <iostream>
#include <string>
#include "courseLL.h"

void courseLL:: insert(string name, string s){	
	course newCourse(name, s);
	node newNode;
	newNode.courseObj = newCourse;
	
	if (head == NULL){
		head = &newNode;
		tail = &newNode;
	}
	else{
		if (length == 1){
			head -> next = &newNode;
		}
		newNode.prev = tail;
		tail -> next = &newNode;
		tail = &newNode;
	}
	length = length + 1;	
}

node*& courseLL:: getHead(){
	return head;
}

string courseLL:: getHeadCourse(){
	return head -> courseObj.getName();
}

int courseLL::getLength(){
	return length;
}

courseLL:: ~courseLL(){
}
