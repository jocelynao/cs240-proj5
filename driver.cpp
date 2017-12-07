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

using namespace std;

int updateTotal(requirements *myRequirements, unordered_map<string, offerings*> map, vector<string> sem){
	int total = 0;
	for(int i = 2; i < sem.size(); i++){
		if(sem[i].substr(0, 2) == "CS"){
			total += map[sem[i]] -> getCredits();
		}
		if(map[sem[i]] -> getTags() != ""){
			for(int j = 0; j < map[sem[i]] -> getTags().length(); j++){
				vector<credit> myCred = myRequirements -> getCreds();
				vector<credit>::iterator iter;
				for(iter = myCred.begin(); iter != myCred.end(); iter++){
					if(iter -> getName() == map[sem[i]] ->getTags().substr(j, j+1)){
						iter -> addAmount(map[sem[i]] -> getCredits());
					}	
				}
			}
		}
	}
	return total;
}

bool checkPlan(requirements *myRequirements, unordered_map<string, offerings*> map, vector<string> sem){
		bool planWorks = true;
		int credsEarned = 0;
		vector<string>:: iterator iter;
		while (planWorks){
			for (int i = 2; i < sem.size(); i++){
				if(map.find(sem[i]) == map.end()){
					cout << "This schedule doesn't work because " << sem[i] << " is not a valid course." << endl;
					planWorks = false;
					break;
				}else{
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
			}

			cout << planWorks << endl;
			if (planWorks){
				planWorks = myRequirements -> check(sem);
			}
			if (planWorks){
		}
		return planWorks;
	}
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
		
		requirementsParser *parser = new requirementsParser(argv[1]);
		requirements *myRequirements = parser -> getRequirements();
	//	cout << "why" << endl;

		offeringsParser *oparser = new offeringsParser(argv[2], myRequirements);
		unordered_map<string, offerings*> map = oparser -> getMap();

		planned *plan = new planned(argv[3]);
	
		bool planWorks = true;
		while(planWorks){
			cout << "IN IT" << endl;
			vector<string> sem = plan -> getSem1();
			planWorks = checkPlan(myRequirements, map, sem);
			if (!planWorks){
				cout << "Bad plan!" << endl;
				break;
			}
			total += updateTotal(myRequirements, map, sem);
			sem = plan -> getSem2();
			planWorks = checkPlan(myRequirements, map, sem);
			if (!planWorks){

				cout << "Bad plan!" << endl;
				break;
			}
			total += updateTotal(myRequirements, map, sem);
			sem = plan -> getSem3();
			planWorks = checkPlan(myRequirements, map, sem);
			if (!planWorks){

				cout << "Bad plan!" << endl;
				break;
			}
			total += updateTotal(myRequirements, map, sem);
			sem = plan -> getSem4();
			planWorks = checkPlan(myRequirements, map, sem);
			if (!planWorks){
				cout << "Bad plan!" << endl;
				break;
			}
			total += updateTotal(myRequirements, map, sem);
			sem = plan -> getSem5();
			planWorks = checkPlan(myRequirements, map, sem);
			if (!planWorks){
				cout << "Bad plan!" << endl;
				break;
			}
			total += updateTotal(myRequirements, map, sem);
			sem = plan -> getSem6();
			planWorks = checkPlan(myRequirements, map, sem);
			if (!planWorks){
				cout << "Bad plan!" << endl;
				break;
			}
			total += updateTotal(myRequirements, map, sem);
			sem = plan -> getSem7();
			planWorks = checkPlan(myRequirements, map, sem);
			if (!planWorks){
				cout << "Bad plan!" << endl;
				break;
			}
			total += updateTotal(myRequirements, map, sem);
			sem = plan -> getSem8();
			planWorks = checkPlan(myRequirements, map, sem);
			if (!planWorks){
				cout << "Bad plan!" << endl;
				break;
			}
			total += updateTotal(myRequirements, map, sem);
			if(total < myRequirements -> getTotal()){
				cout << "Bad plan! You need " << myRequirements -> getTotal() << " credits to graduate, but you only have " << total << endl;
				break;
			}
			vector<credit> myCred = myRequirements -> getCreds();
			vector<credit>::iterator iter;
			for(iter = myCred.begin(); iter != myCred.end(); iter++){
				if(iter -> getAmount() < iter -> getNum()){
					cout << "Bad plan! You need " << iter -> getAmount() << " " << iter ->getName() << " credits to graduate, but you only have " << total << endl;
					break;
				}
			}
			break;
		}
		if (planWorks){
			cout << "Your schedule is good" << endl;
			cout << "total credits: " << total << endl;
		}
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
