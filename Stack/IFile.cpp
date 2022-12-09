#include "IFile.h"
#include <iostream>

using namespace std;

Stack IFile::inputFromFile(char* fileName)
{
	ifstream fin(fileName);
	if (!fin)
	{
		cout << "Cannot open file!" << endl;
		system("pause");
		exit(1);
	}

	int num;
	Stack stack;
	fin.ignore(80, '{');
	while (!fin.eof())
	{
		fin >> num;
		if (!fin.eof()) 
		{
			stack.push(num);
		}
		fin.ignore(256, ',');
	}
	fin.close();
	return stack;
}

void IFile::outputFromFile(char* fileName, Stack stack) 
{
	ofstream fout(fileName);
	if (!fout)
	{
		cout << "Cannot open file!" << endl;
		system("pause");
		exit(1);
	}
	fout.close();
}
