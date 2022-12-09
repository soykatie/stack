#include "MyExceptionClass.h"
#include <string>
#include <iostream>

using namespace std;

MyExceptionClass::MyExceptionClass(const char* str)
{
	strcpy_s(this->str, 200, str);
}

const char* MyExceptionClass::what()
{
	return str;
}