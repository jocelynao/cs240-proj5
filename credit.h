#ifndef CREDITS_H
#define CREDITS_H
#include <iostream>
#include <string>

using namespace std;

class credit{
	private:
		string credName = "";
		int credNum = 0;
		int amount = 0;
	public:
		credit(string name, int num);
		int getAmount();
		void addAmount(int amt);
		void setName(string name);
		void setNum(int num);
		
		string getName();
		int getNum();
};

#endif
