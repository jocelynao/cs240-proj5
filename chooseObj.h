#ifndef CHOOSE_H
#define CHOOSE_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class choose{
	private:
		int amount = 0;
		vector<string> classes;
	public:
		choose(vector<string> line);
		void addClass(string myClass);
		vector<string> getClass();
		void setAmount(int amt);
		int getAmount();
};

#endif
