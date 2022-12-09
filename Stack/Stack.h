#pragma once
#include "Node.h"

class Stack
{
private: 
	Node* head;
public:
	Stack();
	Stack(int);
	Stack(int*, int);
	Stack(const Stack& stack);
	~Stack();

	void push(int);
	void pop();
	bool isEmpty();
	int getSize() const;
	int top();

	char* toString() const;
	Stack operator=(const Stack& ob);

	void redefineStack(const Stack ob);
	void redefineStack(int* arr, int size);
	void static displayStack(Stack&);
	static Stack mergeStack(Stack stack1, Stack stack2);


	void deleteAll();

	friend ostream& operator<<(ostream&, const Stack);
private:
	void addAfter(Node*& node, int value);
};

