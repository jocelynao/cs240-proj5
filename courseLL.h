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
		void insert(string name, string s);

		node*& getHead();
		string getHeadCourse();
		int getLength();

		~courseLL();
};

#endif
