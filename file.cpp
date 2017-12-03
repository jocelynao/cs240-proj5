#include <iostream>
#include <stdlib.h>
#include "FBLCommentsLLH.h"

using namespace std;

FBLCommentsLL::FBLCommentsLL(){
	head = NULL;
	tail = NULL;
}

void FBLCommentsLL::insert(string com, string fn, string ln){
	FBLCommentsNode *newNode = new FBLCommentsNode();
//	cout << "comment that came in: " << com << endl;
	FBLComment newComment(com, fn, ln);
	newNode -> comment = newComment;
	newNode -> next = NULL;
	
	if (head == NULL){
	//	cout << "head is null" << endl;
		head = newNode;
		tail = newNode;

		newNode -> prev = NULL;

	//	length = length + 1;
	}
	else{
		if (length == 1){
	//		cout << "length is 1" << endl;
			head -> next = newNode;
		}
	//	cout << "all other cases" << endl;
		newNode -> prev = tail;
		tail -> next = newNode;
		tail = newNode;
	}
	length = length + 1;
//	FBLCommentsNode *np = head;
/*	for (int i = 0; i < length ; i++){
		cout << "comment in list: " <<  np -> comment.getComment() << endl;
		np = np -> next;
	}*/
}

void FBLCommentsLL::readAZ(){
	FBLCommentsNode *nodePtr = head;
//	cout << length << endl;
	if (length > 0){
		while (nodePtr != NULL){
			cout << nodePtr -> comment.getFN() << " wrote " << nodePtr -> comment.getComment() << endl;
			nodePtr = nodePtr -> next;
		}
	}
	else{
		cout << "No comments" << endl;
	}
}

void FBLCommentsLL::readZA(){
	if (length > 0){
		FBLCommentsNode *nodePtr = tail;
		while (nodePtr != NULL){
			cout << nodePtr -> comment.getFN() << " wrote " << nodePtr -> comment.getComment() << endl;
			nodePtr = nodePtr -> prev;
		}
	}
	else{
		cout << "No comments" << endl;
	}
}

FBLCommentsLL::~FBLCommentsLL(){
	for (int i = 0; i < length; i++){
		FBLCommentsNode *nodePtr = head;
		head = head -> next;
		delete nodePtr;
		nodePtr = NULL;
	}
	head = NULL;
	tail = NULL;

}

