#include <iostream>
#include <string>
#include <vector>
#include <new>
#include "requirementsObj.h"
#include "courseNode.h"

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
		makeNode(reqLine);
	//	printAdjVec();	
	}
	else{
	}
}

bool requirements::alreadyIn(vector<string> vec){
	vector<node*>::iterator iter;
//	cout << adjVecCourses.size() << endl;
	for (iter = adjVecCourses.begin(); iter != adjVecCourses.end(); iter++){
		
		string test = (*iter) -> getCourse();
		if(test.compare(vec[1]) == 0){
			return true;
		}
	}
	return false;
}

void requirements:: makeNode(vector<string> vec){
	node *newNode;
	newNode = new node(vec[1], vec[2]);
	adjVecCourses.push_back(newNode);
}

void requirements:: addReqs(vector<string> reqLine){
//	cout << "in add req" << endl;
	node *coursePtr;
	vector<node*> prereqs;
	vector<node*>:: iterator iter;
	for (int i = 3; i < reqLine.size(); i++){
		bool preReqFound = false;
		for (iter = adjVecCourses.begin(); iter != adjVecCourses.end(); iter++){
			if ((*iter) -> getCourse() == reqLine[i]){
				prereqs.push_back(*iter);
				preReqFound = true;
				break;
			}
		}
		if (!preReqFound){
		//	cout << "1" << endl;
			node *newNode;
			newNode = new node(reqLine[i]);
		//	node newNode(reqLine[i]);
			adjVecCourses.push_back(newNode);
			prereqs.push_back(adjVecCourses[adjVecCourses.size() - 1]);
		}
	}
	for (iter = adjVecCourses.begin(); iter != adjVecCourses.end(); iter++){
		if ((*iter) -> getCourse() == reqLine[1]){
			coursePtr = (*iter);
			coursePtr -> addPreReqs(prereqs);	
		}
	}
	vector<node*>:: iterator iter2;
	for (iter2 = prereqs.begin(); iter2 != prereqs.end(); iter2++){
		//cout << coursePtr -> getCourse() << endl;
		(*iter2) -> addPostReq(coursePtr);
	}
//	cout << "in add req" << endl;
//	printAdjVec();
}

void requirements:: findReqs(){
	vector<node*>:: iterator iter;
	for (iter = adjVecCourses.begin(); iter != adjVecCourses.end(); iter++){
		if ((*iter) -> getStatus() == "R"){
			RCourses.push_back(*iter);
		}
	}
}

void requirements:: addOffs(vector<string> courseOffs){
	//cout << courseOffs[0] << endl;
	vector<string>:: iterator iter;
	//cout << "in addOffs" << endl;
	/*for (iter = courseOffs.begin(); iter != courseOffs.end(); iter++){
		cout << *iter << endl;
	}*/
	if(!alreadyIn(courseOffs)){
	//	cout << "HERE " <<  courseOffs[1] << endl;
		makeNode(courseOffs);
	//	printAdjVec();
		string classAbrv = courseOffs[1].substr(0, 2);
	//	cout << classAbrv << endl;
	/*	if (classAbrv == "CS"){
			vector<node*>:: iterator iter;
			adjVecCourses[adjVecCourses.size() - 1].addPreReqs(RCourses);
			for (iter = RCourses.begin(); iter != RCourses.end(); iter++){
				node *np = &(adjVecCourses[adjVecCourses.size() - 1]);
				(*iter) -> addPostReq(np);
			}
		}*/
	//	cout << courseOffs[1] << " inserted." << endl;
	}
	else{
	//	cout << courseOffs[1] << " already found." << endl;
	}
//	cout << "done" << endl;	
}

bool requirements:: check(vector<string> semClasses){
	bool didPR;
	vector<node*>:: iterator iter;
	for (int i = 2; i < semClasses.size(); i++){
		for (iter = adjVecCourses.begin(); iter != adjVecCourses.end(); iter++){
			if ((*iter) -> getCourse() == semClasses[i]){
				didPR = (*iter) -> checkPR();
				break;
			}
		}
		if (!didPR){
			break;
		}
	}
	return didPR;
}

void requirements:: printAdjVec(){
	
/*	cout << "------------------------------------------" << endl;
	vector<node>:: iterator iter;
	for (iter = adjVecCourses.begin(); iter != adjVecCourses.end(); iter++){
		string test = iter -> getCourse();
		cout << test << endl;
	}
	cout << "------------------------------------------" << endl;*/


//	cout << "WHY" << endl;
//	cout << adjVecCourses[0].getCourse() << endl;
	cout << "------------------------------------------" << endl;
	cout << "Adjacency list: " << endl;
	vector<node*>:: iterator iter;
	for (iter = adjVecCourses.begin(); iter != adjVecCourses.end(); iter++){
	//	cout << "I" << endl;
	//	cout << "E" << endl;
		cout << "Pointer address: " << (*iter) << endl;
		(*iter) -> print();
	}
	cout << "\n" << endl;
	cout << "Required courses: " << endl;
	vector<node*>:: iterator iter2;
	for (iter2 = RCourses.begin(); iter2 != RCourses.end(); iter2++){
		cout << "Pointer address: " << *iter2 << endl;
		try{
			(*iter2) -> print();
		}
		catch (bad_alloc& ba){
			cerr << "bad alloc" << endl;
		}
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

vector<credit> requirements:: getCreds(){
	return creds;
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

