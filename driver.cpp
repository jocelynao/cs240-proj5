#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "Requirements.h"
#include "requirements_parser.h"

using namespace std;

int main(int argc, char **argv){
	if(argc != 4){
		cout << "Please run the program as follows: ./schedule.exe <Requirements File> <Offerings File> <Planned Schedule File>" << endl;
	}else{
		cout << "doing stuff" << endl;
	}
	return 0;
}
