#pragma once
#include <iostream>

using namespace std;

class IConsole
{
public: 
	static void ignoreAll(istream&);
	static int enterIntConsole();
	static int* enterIncreasingSuccession(int);
	static int menu();
};

