#define REQUIREMENTS_H
#ifndef REQUIREMENTS_H

struct node{
	string keyWord;
	node *next;
};

class Requirements{
	public:
		Requirements();
		Requirements* parser(string line);
		string getNode(int node);
	private:
		node *head;
};

#endif
