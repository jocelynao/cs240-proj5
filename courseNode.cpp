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

bool node:: checkPR(){
	bool didPR = false;
	vector<node*>:: iterator iter;
	if (preReqs.size() != 0){
		cout << "You cannot take " << course << "  because you must take these classes as prerequistes: ";
		for (iter = preReqs.begin(); iter != preReqs.end(); iter++){
			cout << (*iter) -> getCourse() << ", ";
		}
		cout << "\n" << endl;
	}
	else{
	//	cout << course << endl;
		for (iter = postReqs.begin(); iter != postReqs.end(); iter++){
			(*iter) -> delPreReq(course);
		}
		didPR = true;
	}
//	cout << "in course node " << didPR << endl;
	return didPR;
}

void node:: delPreReq(string c){
	int i = 0;
	vector<node*>:: iterator iter;
	for (iter = preReqs.begin(); iter != preReqs.end(); iter++, i++){
		if ((*iter) -> getCourse() == c){
			break;
		}
	}
	preReqs.erase(preReqs.begin() + i);
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
//	cout << "in add post req" << endl;
//	cout << ptr -> getCourse() << endl;
//	cout << course << endl;
	if (ptr -> getCourse() != course){
		postReqs.push_back(ptr);
		postLength = postReqs.size();
	}
	vector<node*>:: iterator iter;
//	cout << "ADD" << endl;
/*	for (iter = postReqs.begin(); iter != postReqs.end(); iter++){
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

void node:: setStatus(string s){
	status = s;
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
