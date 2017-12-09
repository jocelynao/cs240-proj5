#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sys/stat.h>
#include "offeringsParser.h"
#include "offeringsObj.h"
#include "plannedObj.h"
#include "requirementsParser.h"
#include "requirementsObj.h"
#include "credit.h"
#include "chooseObj.h"

using namespace std;
vector<credit> genEdCheck(requirements *myRequirements, unordered_map<string, offerings*> map, vector<string> sem, vector<credit> myCred){
	vector<credit>::iterator iter;
	for(int i = 2; i < sem.size(); i++){
		offerings *myOfferings = map[sem[i]];
		string getTags = myOfferings -> getTags();
		if(map[sem[i]] -> getTags() != ""){
			string tags = map[sem[i]] -> getTags();
			for(int j = 0; j < map[sem[i]] -> getTags().length(); j++){
				string myTag;
				stringstream ss;
				char oneTag = tags[j];
				ss << oneTag;
				ss >> myTag;
				for(iter = myCred.begin(); iter != myCred.end(); iter++){
					if(iter -> getName() == myTag){
						iter -> addAmount(map[sem[i]] -> getCredits());
					}	
				}
			}
		}
	}
	return myCred;


}
int updateTotal(requirements *myRequirements, unordered_map<string, offerings*> map, vector<string> sem){
	int total = 0;
	vector<credit>::iterator iter;
	for(int i = 2; i < sem.size(); i++){
		if(sem[i].substr(0, 2) == "CS"){
			total += map[sem[i]] -> getCredits();
		}
	}
	return total;
}

bool chooseCheck(vector<choose*> myChoose, planned *plan){
	bool planWorks = true;
	vector<choose*>::iterator iter;
	int amount = 0;
	for(iter = myChoose.begin(); iter != myChoose.end(); iter++){
		choose *choosing = *iter;
		amount = choosing -> getAmount();
		cout << "amount: " << choosing -> getAmount() << endl;
		vector<string> classes = choosing -> getClass();
		vector<string>::iterator iter1;
		vector<string> taken;

		vector<string>::iterator iter2;
		for(iter1 = classes.begin(); iter1 != classes.end(); iter1++){
			/* checks through each of the semesters for the specified class */
			vector<string> sem = plan -> getSem1();
			string comp1 = *iter1;
			for(iter2 = sem.begin(); iter2 != sem.end(); iter2++){
				string comp2 = *iter2;
				if(comp1 == comp2){
					taken.push_back(comp2);
				}
			}
			sem = plan -> getSem2();			
			for(iter2 = sem.begin(); iter2 != sem.end(); iter2++){
				string comp2 = *iter2;
				if(comp1 == comp2){
					taken.push_back(comp2);
				}
			}
			sem = plan -> getSem3();			
			for(iter2 = sem.begin(); iter2 != sem.end(); iter2++){
				string comp2 = *iter2;
				if(comp1 == comp2){
					taken.push_back(comp2);
				}
			}
			sem = plan -> getSem4();			
			for(iter2 = sem.begin(); iter2 != sem.end(); iter2++){
				string comp2 = *iter2;
				if(comp1 == comp2){
					taken.push_back(comp2);
				}
			}
			sem = plan -> getSem5();			
			for(iter2 = sem.begin(); iter2 != sem.end(); iter2++){
				string comp2 = *iter2;
				if(comp1 == comp2){
					taken.push_back(comp2);
				}
			}
			sem = plan -> getSem6();			
			for(iter2 = sem.begin(); iter2 != sem.end(); iter2++){
				string comp2 = *iter2;
				if(comp1 == comp2){
					taken.push_back(comp2);
				}
			}
			sem = plan -> getSem7();			
			for(iter2 = sem.begin(); iter2 != sem.end(); iter2++){
				string comp2 = *iter2;
				if(comp1 == comp2){
					taken.push_back(comp2);
				}
			}
			cout << endl;
			sem = plan -> getSem8();			
			for(iter2 = sem.begin(); iter2 != sem.end(); iter2++){
				string comp2 = *iter2;
				if(comp1 == comp2){
					taken.push_back(comp2);
				}
			}
		}
		if(taken.size() < amount){
			cout << "This schedule doesn't work because you need at least " << amount << " of the following classes: ";
			for(iter2 = classes.begin(); iter2 != classes.end(); iter2++){
				cout << *iter2 << " ";
			}
			cout << "but you only took " << taken.size() << " of those classes: ";
			for(iter2 = taken.begin(); iter2 != taken.end(); iter2++){
				cout << *iter2 << " ";
			}
			cout << endl;
			return false;
		}
		taken.clear();
	}
	
	return planWorks;
}
bool validClasses(requirements *myRequirements, unordered_map<string, offerings*> offeringsMap, planned *plan){
	bool planWorks = true;
	unordered_map<string, int> taken;
	vector<string> sem = plan -> getSem1();
	for(int i = 2; i < sem.size(); i++){
		if(offeringsMap.find(sem[i]) == offeringsMap.end()){
			cout << "This schedule doesn't work because " << sem[i] << " does not exist in the course offerings." << endl;
			return false;
		}else{
			if(taken.find(sem[i]) == taken.end()){
				taken.insert(make_pair(sem[i], 0));
			}else{
				cout << "This schedule doesn't work because you inputted " << sem[i] << " more than once." << endl;
				return false;
			}
		}
	}
	sem = plan -> getSem2();
	for(int i = 2; i < sem.size(); i++){
		if(offeringsMap.find(sem[i]) == offeringsMap.end()){
			cout << "This schedule doesn't work because " << sem[i] << " does not exist in the course offerings." << endl;
			return false;
		}else{
			if(taken.find(sem[i]) == taken.end()){
				taken.insert(make_pair(sem[i], 0));
			}else{
				cout << "This schedule doesn't work because you inputted " << sem[i] << " more than once." << endl;
				return false;
			}
		}
	}
	sem = plan -> getSem3();
	for(int i = 2; i < sem.size(); i++){
		if(offeringsMap.find(sem[i]) == offeringsMap.end()){
			cout << "This schedule doesn't work because " << sem[i] << " does not exist in the course offerings." << endl;
			return false;
		}else{
			if(taken.find(sem[i]) == taken.end()){
				taken.insert(make_pair(sem[i], 0));
			}else{
				cout << "This schedule doesn't work because you inputted " << sem[i] << " more than once." << endl;
				return false;
			}
		}
	}
	sem = plan -> getSem4();
	for(int i = 2; i < sem.size(); i++){
		if(offeringsMap.find(sem[i]) == offeringsMap.end()){
			cout << "This schedule doesn't work because " << sem[i] << " does not exist in the course offerings." << endl;
			return false;
		}else{
			if(taken.find(sem[i]) == taken.end()){
				taken.insert(make_pair(sem[i], 0));
			}else{
				cout << "This schedule doesn't work because you inputted " << sem[i] << " more than once." << endl;
				return false;	
			}
		}
	}
	sem = plan -> getSem5();
	for(int i = 2; i < sem.size(); i++){
		if(offeringsMap.find(sem[i]) == offeringsMap.end()){
			cout << "This schedule doesn't work because " << sem[i] << " does not exist in the course offerings." << endl;
			return false;
		}else{
			if(taken.find(sem[i]) == taken.end()){
				taken.insert(make_pair(sem[i], 0));
			}else{
				cout << "This schedule doesn't work because you inputted " << sem[i] << " more than once." << endl;
				return false;
			}
		}
	}
	sem = plan -> getSem6();
	for(int i = 2; i < sem.size(); i++){
		if(offeringsMap.find(sem[i]) == offeringsMap.end()){
			cout << "This schedule doesn't work because " << sem[i] << " does not exist in the course offerings" << endl;
			return false;
		}else{
			if(taken.find(sem[i]) == taken.end()){
				taken.insert(make_pair(sem[i], 0));
			}else{
				cout << "This schedule doesn't work because you inputted " << sem[i] << " more than once." << endl;
				return false;
			}
		}
	}
	sem = plan -> getSem7();
	for(int i = 2; i < sem.size(); i++){
		if(offeringsMap.find(sem[i]) == offeringsMap.end()){
			cout << "This schedule doesn't work because " << sem[i] << " does not exist in the course offerings." << endl;
			return false;
		}else{
			if(taken.find(sem[i]) == taken.end()){
				taken.insert(make_pair(sem[i], 0));
			}else{
				cout << "This schedule doesn't work because you inputted " << sem[i] << " more than once." << endl;
				return false;
			}
		}
	}
	sem = plan -> getSem8();
	for(int i = 2; i < sem.size(); i++){
		if(offeringsMap.find(sem[i]) == offeringsMap.end()){
			cout << "This schedule doesn't work because " << sem[i] << " does not exist in the course offerings." << endl;
			return false;
		}else{
			if(taken.find(sem[i]) == taken.end()){
				taken.insert(make_pair(sem[i], 0));
			}else{
				cout << "This schedule doesn't work because you inputted " << sem[i] << " more than once." << endl;
				return false;
			}
		}
	}

	return planWorks;
}

bool checkPlan(requirements *myRequirements, unordered_map<string, offerings*> map, vector<string> sem){
	bool planWorks = true;
	int credsEarned = 0;
//	cout << "267" << endl;
	vector<string>:: iterator iter;
/*	for (iter = sem.begin(); iter != sem.end(); iter++){
		cout << *iter << endl;
	}
	cout << "end iter" << endl;*/
	while (planWorks){
		for (int i = 2; i < sem.size(); i++){

			if(map[sem[i]] -> getTerm() != sem[0] && 
					map[sem[i]] -> getTerm() != "E"){
				if(sem[0] == "F"){
					cout << "This schedule doesn't work because " << sem[i] << " can only be taken during the spring semester and you're trying to take it in " << sem[1] << endl;
				}
				else{
					cout << "This schedule doesn't work because " << sem[i] << " can only be taken during the fall semester and you're trying to take it in " << sem[1] << endl;
				}
				planWorks = false;
				break;
			}	
		}

	//	cout << planWorks << endl;
		if (planWorks){
		//	cout << "2" << endl;
			planWorks = myRequirements -> check(sem);
			break;
		}
	}
	return planWorks;
}

int main(int argc, char **argv){
	if(argc != 4){
		cout << "Please run the program as follows: ./schedule.exe <Requirements File> <Offerings File> <Planned Schedule File>" << endl;
	}else{
		
		bool exists = false;
		struct stat b;
		int total = 0;
		string fileName;
		for(int i = 1; i < 4; i++){
			fileName = argv[i];
			exists = (stat(fileName.c_str(), &b) == 0);
			if(!exists){
				cout << "File " << fileName << " could not be found!" << endl;
				exit(0);
			}
		}
	//	cout << "315" << endl;	
		requirementsParser *parser = new requirementsParser(argv[1]);
	//	cout << "318" << endl;
		requirements *myRequirements = parser -> getRequirements();
		offeringsParser *oparser = new offeringsParser(argv[2], myRequirements);
	//	cout << "320" << endl;
		unordered_map<string, offerings*> map = oparser -> getMap();
		vector<credit> myCred = myRequirements -> getCreds();

		planned *plan = new planned(argv[3]);
	//	cout << "323" << endl;
		bool planWorks = true;
		bool checkedAll = false;
		while(planWorks){
			vector<string> sem = plan -> getSem1();
			vector<string>::iterator iter1;
		/*	for (iter1 = sem.begin(); iter1 != sem.end(); iter1++){
				cout << *iter1 << endl;
			}*/
		//	cout <<"done" << endl;
			planWorks = validClasses(myRequirements, map, plan);
		//	cout << "HERE" << endl;
			if(!planWorks){
			//	cout << "here" << endl;
				break;
			}
			planWorks = checkPlan(myRequirements, map, sem);
		//	cout << "HI" << endl;
		//	cout << "here" << endl;
			if (!planWorks){
				break;
			}
			total += updateTotal(myRequirements, map, sem);
			myCred = genEdCheck(myRequirements, map, sem, myCred);
			sem = plan -> getSem2();
		//	cout << "here2" << endl;			
		/*	for(iter1 = sem.begin(); iter1 != sem.end(); iter1++){
				cout << *iter1 << " ";
			}
			cout << endl << "-----------------------" << endl;*/
			planWorks = checkPlan(myRequirements, map, sem);
			if (!planWorks){
				break;
			}
			total += updateTotal(myRequirements, map, sem);
			myCred = genEdCheck(myRequirements, map, sem, myCred);
			sem = plan -> getSem3();		
			for(iter1 = sem.begin(); iter1 != sem.end(); iter1++){
				cout << *iter1 << " ";
			}
			cout << endl << "-----------------------" << endl;
			planWorks = checkPlan(myRequirements, map, sem);
			if (!planWorks){
				break;
			}
			total += updateTotal(myRequirements, map, sem);
			myCred = genEdCheck(myRequirements, map, sem, myCred);
			sem = plan -> getSem4();			
			for(iter1 = sem.begin(); iter1 != sem.end(); iter1++){
				cout << *iter1 << " ";
			}
			cout << endl << "-----------------------" << endl;
			planWorks = checkPlan(myRequirements, map, sem);
			if (!planWorks){
				break;
			}
			total += updateTotal(myRequirements, map, sem);
			myCred = genEdCheck(myRequirements, map, sem, myCred);
			sem = plan -> getSem5();
			for(iter1 = sem.begin(); iter1 != sem.end(); iter1++){
				cout << *iter1 << " ";
			}
			cout << endl << "-----------------------" << endl;
			planWorks = checkPlan(myRequirements, map, sem);
			if (!planWorks){
				break;
			}
			total += updateTotal(myRequirements, map, sem);
			myCred = genEdCheck(myRequirements, map, sem, myCred);
			sem = plan -> getSem6();
			for(iter1 = sem.begin(); iter1 != sem.end(); iter1++){
				cout << *iter1 << " ";
			}
			cout << endl << "-----------------------" << endl;
			planWorks = checkPlan(myRequirements, map, sem);
			if (!planWorks){
				break;
			}
			total += updateTotal(myRequirements, map, sem);
			myCred = genEdCheck(myRequirements, map, sem, myCred);
			sem = plan -> getSem7();
			for(iter1 = sem.begin(); iter1 != sem.end(); iter1++){
				cout << *iter1 << " ";
			}
			cout << endl << "-----------------------" << endl;
			planWorks = checkPlan(myRequirements, map, sem);
			if (!planWorks){
				break;
			}
			total += updateTotal(myRequirements, map, sem);
			myCred = genEdCheck(myRequirements, map, sem, myCred);
			sem = plan -> getSem8();
			for(iter1 = sem.begin(); iter1 != sem.end(); iter1++){
				cout << *iter1 << " ";
			}
			cout << endl << "-----------------------" << endl;
			planWorks = checkPlan(myRequirements, map, sem);
			checkedAll = true;
			if (!planWorks){
				break;
			}
			total += updateTotal(myRequirements, map, sem);
			myCred = genEdCheck(myRequirements, map, sem, myCred);
			if(total < myRequirements -> getTotal()){
				cout << "Bad plan! You need " << myRequirements -> getTotal() << " credits to graduate, but you only have " << total << endl;
				planWorks = false;
			//	cout << "432" << endl;
				break;
			}
		//	cout << "435" << endl;
			vector<credit>::iterator iter;
			for(iter = myCred.begin(); iter != myCred.end(); iter++){
				if(iter -> getAmount() < iter -> getNum()){
					cout << "Bad plan! You need " << iter -> getNum() << " " << iter ->getName() << " credits to graduate, but you only have " << iter -> getAmount() << endl;
					planWorks = false;
					break;
				}
			}
			if (!planWorks){
				break;
			}
			planWorks = chooseCheck(myRequirements -> getChooseVec(), plan);
		//	cout << "437" << endl;
			if (planWorks){
			//	cout << "444" << endl;
				planWorks = myRequirements -> checkMandRs();
			}
			break;
		}
		if (!checkedAll){
			cout << "Whole schedule was not checked because of error stated above" << endl;
		}
		if (planWorks){
			cout << "Your schedule is good" << endl;
			cout << "total credits: " << total << endl;
		}
		
		oparser -> deleteAll();
		delete oparser;
		parser -> deleteAll();
		delete parser;
		delete plan;
		

			//	myRequirements -> check(firstSem);

	//	(parser -> getRequirements()) -> printAdjVec();
		/*
		unordered_map<string, offerings*> offersMap;
		offeringsParser *offers = new offeringsParser(argv[2]);
		offersMap = offers -> getMap();
		
		auto search = offersMap.find("AN301");
		if(search != offersMap.end()){
			cout << "Found " << search -> first << " : " << search -> second -> getCredits();
		}

		vector<string> plannedTest;
		vector<string>::iterator iter;
		planned *plan = new planned(argv[3]);
		plannedTest = plan -> getF19();
		cout << endl << endl;

		for(iter = plannedTest.begin(); iter != plannedTest.end(); iter++){
			cout << *iter << ", "; 
		}
		cout << endl;
		*/
		
	}
	return 0;
}
