#ifndef CLASSLL_H
#define CLASSLL_H
#include <iostream>
#include <string>
#include "course.h"

using namespace std;

class node{
	public:
		course courseObj;
		node *next = NULL;
		node *prev = NULL;
};

class courseLL{
	private:
		node *head;
		node *tail;
		int length = 0;
	public:
		string getHead();
		void insert(string name, string s);
		~courseLL();
};

#endif
