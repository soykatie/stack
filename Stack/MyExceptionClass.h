#pragma once

class MyExceptionClass
{
private:
	char str[200];
public:
	MyExceptionClass(const char* str);
	const char* what();
};

