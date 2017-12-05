#include <iostream>
#include <string>
#include "courseNode.h"

node:: node(string c, string s){
	course = c;
	status = s;
}

node:: node(string c){
	course = c;
}

void node:: print(){
	vector<node*>:: iterator iter;
	cout << course << " " <<  status << endl;
	cout << "Post reqs: ";;
	for (iter = postReqs.begin(); iter != postReqs.end(); iter++){
	//	cout << "W" << endl;
		cout << (*iter) -> getCourse() << " " << (*iter) -> getStatus() <<  ", ";
	}
	cout << "\nPre reqs: ";
	for (iter = preReqs.begin(); iter != preReqs.end(); iter++){
		cout << (*iter) -> getCourse() << " " << (*iter) -> getStatus() << ", ";
	}
	cout << "\n" << endl;
}

void node:: addPostReq(node *&ptr){
	postReqs.push_back(ptr);
	postLength = postReqs.size();
/*	vector<node*>:: iterator iter;
	cout << "ADD" << endl;
	for (iter = postReqs.begin(); iter != postReqs.end(); iter++){
		cout << (*iter) -> getCourse() << endl;
	}*/
}

void node:: addPreReqs(vector<node*> vecNP){
	copy(vecNP.begin(), vecNP.end(), back_inserter(preReqs));
	preLength = preReqs.size();
}

string node:: getCourse(){
	return course;
}

string node:: getStatus(){
	return status;
}

int node:: getPostLength(){
	return postLength;
}

int node:: getPreLength(){
	return preLength;
}

/*void courseLL:: insert(string name, string s){	
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

void courseLL:: printLL(){
	node *nodePtr = head;
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
}*/
