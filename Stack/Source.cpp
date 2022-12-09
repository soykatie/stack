#pragma once
#include "IConsole.h"
#include "IFile.h"
#include "Stack.h"
#include "Node.h"
#include "MyExceptionClass.h"
#include <iostream>

using namespace std;

int main()
{
	int choice;
	Stack stack1;
	int value;
	
	int array[9] = { 1, 3, 4, 6, 7, 9, 10, 11, 12 };
	Stack stack(array, 9);

	while (true)
	{
		choice = IConsole::menu();

		switch (choice)
		{
		case 1:
		{
			Node node;
			cout << "Test Node(): " << node << endl;
			break;
		}
		case 2:
		{
			cout << "Enter int number: " << endl;
			value = IConsole::enterIntConsole();
			Node node(value);
			cout << "Test Node(" << value << "): " << node << endl;
			break;
		}
		case 3: 
		{
			cout << "Stack: " << stack1 << endl;
			break;
		}
		case 4:
		{
			Stack stack2;
			stack1 = Stack();
			cout << "Test Stack(): " << stack1 << endl;
			break;
		}
		case 5:
		{
			cout << "Enter int number: " << endl;
			value = IConsole::enterIntConsole();
			Stack stack1(value);
			cout << "Test Stack(" << value << "): " << stack1 << endl;
			break;
		}
		case 6:
		{
			cout << "Enter size of stack: " << endl;
			int size = IConsole::enterIntConsole();
			int* arr = new int[size];
			for (int i = 0; i < size; i++)
			{
				cout << "Enter stack[" << i << "]: " << endl;
				arr[i] = IConsole::enterIntConsole();
			}
			Stack stack1(arr, size);
			cout << "Test Stack(stack, size): " << endl << stack1 << endl;
			break;
		}

		case 7:
		{
			Stack stack2(stack);
			cout << "Test copy Stack(" << stack << "): " << stack << endl;
			break;
		}
		case 8:
		{
			cout << "Enter int number: " << endl;
			value = IConsole::enterIntConsole();
			stack1.push(value);
			cout << "Test push " << value << ": " << stack1 << endl;
			break;
		}
		case 9:
		{
			cout << "Test pop, stack before deleting: " << stack << endl;
			stack.pop();
			cout << "Test pop, stack after deleting: " << stack << endl;
			break;
		}
		case 10:
		{
			cout << "Enter size of first stack: " << endl;
			int size1 = IConsole::enterIntConsole();
			int* arr1 = IConsole::enterIncreasingSuccession(size1);
			Stack s1(arr1, size1);

			cout << "Enter size of second stack: " << endl;
			int size2 = IConsole::enterIntConsole();
			int* arr2 = IConsole::enterIncreasingSuccession(size2);
			Stack s2(arr2, size2);

			cout << "Stack 1: " << s1 << endl;
			cout << "Stack 2: " << s2 << endl;

			stack1 = Stack::mergeStack(s2, s1);
			cout << "Merge 2 stacks from console: " << stack1 << endl;
			break;
		}
		case 11:
		{
			cout << "Enter file name for input date for Stack 1: ";
			char fileName1[80] = "";
			cin >> fileName1;
			Stack s1 = IFile::inputFromFile(fileName1);
			cout << "Stack" << endl << s1 << endl;

			cout << "Enter file name for input date for Stack 2: ";
			char fileName2[80] = "";
			cin >> fileName2;
			Stack s2 = IFile::inputFromFile(fileName2);
			cout << "Stack" << endl << s2 << endl;

			stack1 = Stack::mergeStack(s2, s1);
			cout << "Merge 2 stacks from file: " << stack1 << endl;
			break;
		}
		case 12:
		{
			cout << "Enter file name for input data:";
			char fileName[80] = "";
			cin >> fileName;
			stack1 = IFile::inputFromFile(fileName);
			cout << "Stack" << endl << stack << endl;
			break;
		}
		case 13:
		{
			cout << "Enter file name for output data:";
			char fileName[80] = "";
			cin >> fileName;
			IFile::outputFromFile(fileName, stack1);
			break;
		}
		case 14:
		{
			cout << "Test delete all, stack before deleting: " << stack << endl;
			stack.deleteAll();
			cout << "Test delete all, stack after deleting: " << stack << endl;
			break;
		}
		case 15:
		{
			return 0;
		}
		}
	}

    return 0;
}
