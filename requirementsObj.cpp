#include <iostream>
#include <string>
#include <vector>
#include "requirementsObj.h"

using namespace std;

void requirements:: setCourses(vector<string> reqLine){
	if (reqLine[0] == "TOTAL"){
		setTotal(stoi(reqLine[1]));
	//	cout << getTotal() << endl;

	}
	else if(reqLine[0] == "CREDIT"){
		credit newCred(reqLine[1], stoi(reqLine[2]));
		creds.push_back(newCred);
	//	vector<credit>:: iterator cIter;
	/*	for (cIter = creds.begin(); cIter != creds.end(); cIter++){
			cot << cIter -> getName() << ", ";
		}
		cout << "\n" << endl;*/

	}
	else if(reqLine[0] == "COURSE"){
	//	cout << "hello" << endl;
		makeNode(reqLine);		
	}
	else{
		cout << "HI" << endl;
	}
}

void requirements:: makeNode(vector<string> vec){
	node *newNode;
	newNode = new node(vec[1], vec[2]);
//	cout << newNode.getStatus() << endl;
//	cout << newNode.getCourse() << endl;
	if (vec[2] == "R"){
		RCourses.push_back(newNode);
	}
	adjVecCourses.push_back(*newNode);
}

void requirements:: addReqs(vector<string> reqLine){
//	cout << "E" << endl;
	node *coursePtr;
	vector<node*> PR;
	vector<node>:: iterator iter;
	for (int i = 3; i < reqLine.size(); i++){
		bool preReqFound = false;
		for (iter = adjVecCourses.begin(); iter != adjVecCourses.end(); iter++){
			if (iter -> getCourse() == reqLine[i]){	
				PR.push_back(&(*iter));
				preReqFound = true;
				break;
			}
		}
		if (!preReqFound){
		//	cout << "1" << endl;
			node *newNode;
			newNode = new node(reqLine[i]);
		//	node newNode(reqLine[i]);
			adjVecCourses.push_back(*newNode);
			PR.push_back(newNode);
		}
	}
	for (iter = adjVecCourses.begin(); iter != adjVecCourses.end(); iter++){
		if (iter -> getCourse() == reqLine[1]){
			coursePtr = &(*iter);
			coursePtr -> addPreReqs(PR);	
		}
	}
	vector<node*>:: iterator iter2;
	for (iter2 = PR.begin(); iter2 != PR.end(); iter2++){
		(*iter2) -> addPostReq(coursePtr);
	}
//	printAdjVec();
}

/*void requirements:: addReqs(vector<string> reqLine){
	cout << "E" << endl;
	node *coursePtr;
	vector<node*> PR;
	vector<node>:: iterator iter;
	for (iter = adjVecCourses.begin(); iter != adjVecCourses.end(); iter++){
		if (iter -> getCourse() == reqLine[1]){
			cout << iter -> getCourse() << endl;
			coursePtr = &(*iter);
			cout << "i" << endl;
			cout << coursePtr -> getCourse() << endl;
			cout << "i" << endl;
		}
	}
	for (int i = 3; i < reqLine.size(); i++){
		bool preReqFound = false;
		cout << "ii" << endl;
		cout << coursePtr -> getCourse() << endl;
		cout << "ii" << endl;

		for (iter = adjVecCourses.begin(); iter != adjVecCourses.end(); iter++){
			if (iter -> getCourse() == reqLine[i]){	
				iter -> addPostReq(coursePtr);
				printAdjVec();
				PR.push_back(&(*iter));
				preReqFound = true;
			}
		}
		if (!preReqFound){
			cout << "iii" << endl;
			cout << coursePtr -> getCourse() << endl;
			cout << "iii" << endl;

		//	cout << "HERE: " << reqLine[i] << endl;
			node *newNode;
			newNode = new node(reqLine[i]);
		//	cout << "not preqreq found" << endl;
		//	newNode.addPostReq(coursePtr);
		//	newNode.print();
			cout << "5" << endl;
			cout << coursePtr -> getCourse() << endl;
		//	cout << coursePtr2 -> getCourse() << endl;
			cout << "5" << endl;
			newNode -> addPostReq(coursePtr);
			adjVecCourses.push_back(*newNode);
			cout << "6" << endl;
			cout << coursePtr -> getCourse() << endl;
			cout << "6" << endl;
		//	adjVecCourses[adjVecCourses.size() - 1].addPostReq(coursePtr);
		//	adjVecCourses[adjVecCourses.size() - 1].print();
			PR.push_back(newNode);
		//	node newNode(reqLine[i]);
		//	newNode.addPostReq(coursePtr);
		//	adjVecCourses.push_back(newNode);
		//	newNode.print();
		//	printAdjVec();
		//	PR.push_back(&newNode);
		}
	}
	vector<node*>:: iterator iter2;
//	cout << "HERE: " << PR[PR.size() - 1] -> getCourse() << endl;
	coursePtr -> addPreReqs(PR);
	printAdjVec();
//	coursePtr -> print();
}
*/
void requirements:: printAdjVec(){
//	cout << "WHY" << endl;
//	cout << adjVecCourses[0].getCourse() << endl;
	cout << "------------------------------------------" << endl;
	cout << "Adjacency list: " << endl;
	vector<node>:: iterator iter;
	for (iter = adjVecCourses.begin(); iter != adjVecCourses.end(); iter++){
	//	cout << "I" << endl;
	//	cout << "E" << endl;
		iter -> print();
	}
	cout << "\n" << endl;
	cout << "Required courses: " << endl;
	vector<node*>:: iterator iter2;
	for (iter2 = RCourses.begin(); iter2 != RCourses.end(); iter2++){
		(*iter2) -> print();
	}
	cout << "---------------------------------------------" << endl;
//	cout << "HOW" << endl;
}

void requirements:: setTotal(int n){
	total = n;
}

int requirements:: getTotal(){
	return total;
}

/*void requirements:: makeNode(vector<string> vec){
	node newNode(vec[1], vec[2]);
//	cout << newNode.getStatus() << endl;
//	cout << newNode.getCourse() << endl;
	adjVecCourses.push_back(newNode);
//	cout << adjVecCourses[0].getCourse() << endl;
//	cout << adjVecCourses.size() << endl;
//`	cout << "I" << endl;
//	printAdjVec();
//	cout << "end" << endl;
	courseLL *newCLL = new courseLL;
	newCLL -> insert(vec[1], vec[2]);
	adjVecCourses.push_back(*newCLL);*/
//	cout << newCLL -> getHeadCourse() << endl;
//}

/*void requirements:: insertLL(vector<string> vec){
	courseLL *newCLL = new courseLL;
	vector<string>::iterator iter;
	int i = 0;
	for(iter = vec.begin(); iter != vec.end(); iter++){
		if(i != 0){
			if(i == 1){
				newCLL -> insert(vec[i], vec[i+1]);
			}else{
				if(i != 2){
					newCLL -> insert(vec[i], "");
				}
			}
		}
		i++;
	}
//	cout << newCLL -> getHeadCourse() << endl;
}*/

