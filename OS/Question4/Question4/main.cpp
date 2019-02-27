/*Program to open a file and write into it in Windows*/

#include<stdio.h>
#include<Windows.h>
#include<tchar.h>

int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hfile;
	BOOL ret;
	DWORD nbr;
	TCHAR buffer[] = TEXT("This is the text written into the file called fileA");

	hfile = CreateFile(argv[1], GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	//File was not opened successfully
	if (INVALID_HANDLE_VALUE == hfile) {
		_tprintf(_T("Unable to open %s Error: %d\n"), argv[1], GetLastError());
	}

	//File was opened successfully
	else {
		_tprintf(_T("Opened %s\n"), argv[1]);
		ret = WriteFile(hfile, buffer, sizeof(buffer), &nbr, NULL);
		if (TRUE == ret)
		{
			_tprintf(_T("Successfully written to %s\n"), argv[1]);
		}
		else {
			_tprintf(_T("Unable to write to %s Error: %d\n"), argv[1], GetLastError());
		}
	}

	CloseHandle(hfile);
	return true;
}
