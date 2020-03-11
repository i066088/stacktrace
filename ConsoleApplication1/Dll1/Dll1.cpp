// Dll1.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Dll1.h"
#include <iostream>
#include <stdarg.h>
#include <ctype.h>
#include <windows.h>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <fstream>
#include <crtdbg.h>
#include "DbgHelp.h"
#pragma comment(lib, "Dbghelp.lib")
#define ERROR_TRACE_STACK 10

// This is an example of an exported variable
DLL1_API int nDll1=0;

// This is an example of an exported function.
DLL1_API int fnDll1(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CDll1::CDll1()
{
    return;
}


DLL1_API BOOL foo()
{
	DWORD  error;

	SymSetOptions(SYMOPT_LOAD_LINES); //SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS | SYMOPT_LOAD_LINES

	HANDLE process = GetCurrentProcess();
	if (!SymInitialize(process, NULL, TRUE))
	{
		// SymInitialize failed
		printf("SymInitialize returned error : %d\n", GetLastError());
		return FALSE;
	}

	void* stack[ERROR_TRACE_STACK];
	unsigned short frames = CaptureStackBackTrace(0, ERROR_TRACE_STACK, stack, NULL);

	char szSymbol[sizeof(SYMBOL_INFO) + 256 * sizeof(char)] = { 0 };
	SYMBOL_INFO *symbol = (SYMBOL_INFO *)szSymbol;
	symbol->MaxNameLen = 255;
	symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
	for (unsigned short i = 0; i < frames; i++)
	{
		DWORD displacement = 0;

		BOOL rt = SymFromAddr(process, (DWORD64)(stack[i]), 0, symbol);

		IMAGEHLP_MODULE64 moduleInfo = { 0 };
		moduleInfo.SizeOfStruct = sizeof(IMAGEHLP_MODULE64);
		rt = SymGetModuleInfo64(process, (DWORD64)(stack[i]), &moduleInfo);

		IMAGEHLP_LINE64 line = { 0 };
		line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);
		rt = SymGetLineFromAddr64(process, (DWORD64)(stack[i]), &displacement, &line);

		std::stringstream stream;
		stream << std::setw(i) << "" << (line.FileName ? line.FileName : " No Source File ") << "(" << line.LineNumber << ") : 0x"
			<< stack[i] << " : " << (symbol->Name[0] != 0 ? symbol->Name : "No Symbol Name")
			<< " : " << moduleInfo.ImageName << std::endl;

		OutputDebugStringA(stream.str().c_str());
		std::cout << stream.str().c_str();
	}
}
