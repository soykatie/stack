#pragma once
#include "Stack.h"
#include <fstream>

class IFile
{
public:
	static Stack inputFromFile(char* fileName);
	static void outputFromFile(char* fileName, Stack stack);
};

