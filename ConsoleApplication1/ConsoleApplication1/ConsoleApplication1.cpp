// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdarg.h>
#include <ctype.h>
#include <windows.h>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <fstream>

#include "Dll1.h"
int main()
{	
	foo();

	int integerVariable = 1;
	char msgbuf[1024];
	sprintf_s(msgbuf, 1024, "My variable is %d\n", integerVariable);
	OutputDebugString(msgbuf);
	return 0;
}
