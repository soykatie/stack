#include "IConsole.h"

#define MAX_CHAR 256

void IConsole::ignoreAll(istream& is)
{
	is.clear();
	is.sync();
	is.ignore(is.rdbuf()->in_avail());
}

int IConsole::enterIntConsole()
{
	int n;
	cin >> n;
	while (cin.fail())
	{
		cin.clear();
		char c[MAX_CHAR];
		cin >> c;
		cout << "Try again! This is not a number!" << endl;
		cin >> n;
	}
	ignoreAll(cin);
	return n;
}

int* IConsole::enterIncreasingSuccession(int size)
{
	int* st = new int[size];
	cout << "Enter non-decreasing succession" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter stack[" << i << "]: " << endl;
		st[i] = IConsole::enterIntConsole();
		while((i > 0) && (st[i] < st[i - 1])) 
		{
			cout << "Please, enter non-decreasing succession! Try again!" << endl;
			cout << "Enter stack[" << i << "]: " << endl;
			st[i] = IConsole::enterIntConsole();
		}
	}
	return st;
}

int IConsole::menu()
{
	int choice;
	do
	{
		cout << endl << "STACK CLASS MENU: " << endl;
		cout << "1 -  test Node()" << endl;
		cout << "2 -  test Node(int)" << endl;
		cout << "3 - display stack" << endl;
		cout << "4 -  test Stack()" << endl;
		cout << "5 -  test Stack(int)" << endl;
		cout << "6 -  test Stack(array, size)" << endl;
		cout << "7 -  test copy Stack(int)" << endl;
		cout << "8 -  push" << endl;
		cout << "9 -  pop" << endl;
		cout << "10 - merge 2 stacks from console" << endl;
		cout << "11 - merge 2 stacks from file" << endl;
		cout << "12 -  read stack from file" << endl;
		cout << "13 -  write stack from file" << endl;
		cout << "14 -  delete all" << endl;
		cout << "15 - quit" << endl;
		cout << endl;
		cout << "Enter your choice: " << endl;
		choice = enterIntConsole();
	} while ((choice < 1) || (choice > 16));
	return choice;
}
