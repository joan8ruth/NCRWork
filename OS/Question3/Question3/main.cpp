/*Opening a file and reading from a file in windows*/

#include<stdio.h>
#include<Windows.h>
#include<tchar.h>

#define BUFFSIZE 100

int _tmain(int argc,LPTSTR argv[])
{
	HANDLE hfile,hfile2;
	TCHAR buffer[BUFFSIZE] = { 0 };
	BOOL ret;
	DWORD nbr;

	//Creating a new file
	hfile = CreateFile(argv[1], GENERIC_READ, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == hfile) {
		_tprintf(_T("Unable to open %s Error: %d\n"), argv[1],GetLastError());
	}

	else {
		_tprintf(_T("Opened %s"), argv[1]);
	}

	//Reading from an existing file
	hfile2= CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	ret = ReadFile(hfile2, buffer, BUFFSIZE, &nbr, NULL);

	if (0 == ret) {
		_tprintf(_T("Can't read file %s Error:%d"), argv[1], GetLastError());
		return FALSE;
	}

	else {
		_tprintf(_T("Text from %s is :\n%S"), argv[1],buffer);
		return TRUE;
	}
	CloseHandle(hfile);
	CloseHandle(hfile2);
	
}