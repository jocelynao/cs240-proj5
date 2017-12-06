#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sys/stat.h>
#include "offeringsParser.h"
#include "plannedObj.h"
#include "requirementsParser.h"
#include "requirementsObj.h"

using namespace std;

bool checkPlan(requirements *myRequirements, unordered_map<string, offerings*> map, vector<string> sem){
//	cout << "in check plan" << endl;
	bool planWorks = true;
	int credsEarned = 0;
	vector<string>:: iterator iter;
/*	for (iter = sem.begin(); iter != sem.end(); iter++){
		cout << *iter << endl;
	}
	cout << "end going through sem" << endl;*/
	while (planWorks){
	//	vector<string> firstSem = plan -> getF16();
		cout << "in while plan works" << endl;
		for (int i = 2; i < sem.size(); i++){
			cout << sem[i] << endl;

		/*	cout << i << endl;
			cout << firstSem[i] << endl;
			cout << map["HI101"] -> getClass() << endl;
			cout << map[firstSem[i]] -> getClass() << endl;*/
		//	cout << map[sem[i]] -> getTerm() << endl;
		//	cout << sem[0] << endl;
			if (map[sem[i]] -> getTerm() != sem[0] && 
					map[sem[i]] -> getTerm() != "E"){
				if (sem[0] == "F"){
					cout << "This schedule doesn't work because " << sem[i] << " can only be taken during the spring semester and you're trying to take it in " << sem[1] << endl;
				}
				else{
					cout << "This schedule doesn't work because " << sem[i] << " can only be taken during the fall semester and you're trying to take it in " << sem[1] << endl;
				}
				planWorks = false;
				break;
			}
		}
	//	cout << "issue" << endl;
		if (planWorks){
		//	cout << "hello" << endl;
			planWorks = myRequirements -> check(sem);
		//	cout << "here" << endl;
		}
		break;
	}
//	cout << "i" << endl;
	cout << "done with checkPlan" << endl;
	return planWorks;
}

int main(int argc, char **argv){
	if(argc != 4){
		cout << "Please run the program as follows: ./schedule.exe <Requirements File> <Offerings File> <Planned Schedule File>" << endl;
	}else{
		
		bool exists = false;
		struct stat b;
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
/*		unordered_map<string, offerings*> map = oparser -> getMap();

		planned *plan = new planned(argv[3]);
	
		bool planWorks = true;
		while(planWorks){
			vector<string> sem = plan -> getF16();
			planWorks = checkPlan(myRequirements, map, sem);
			if (!planWorks){
				break;
			}
			sem = plan -> getS17();
			planWorks = checkPlan(myRequirements, map, sem);
			if (!planWorks){
				break;
			}
			sem = plan -> getF17();
			planWorks = checkPlan(myRequirements, map, sem);
			if (!planWorks){
				break;
			}
			sem = plan -> getS18();
			planWorks = checkPlan(myRequirements, map, sem);
			if (!planWorks){
				break;
			}
			sem = plan -> getF19();
			planWorks = checkPlan(myRequirements, map, sem);
		//	cout << "seg" << endl;
			if (!planWorks){
				break;
			}
			sem = plan -> getS20();
			planWorks = checkPlan(myRequirements, map, sem);
			if (!planWorks){
				break;
			}

			break;
		}
		if (planWorks){
			cout << "Your schedule is good" << endl;
		}*/
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
