/*Program to create a process which is also a console apllication*/

#include<stdio.h>
#include<Windows.h>
#include<tchar.h>

int _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO si1;
	PROCESS_INFORMATION pi1;
	SECURITY_ATTRIBUTES sa;
	HANDLE hproc;
	DWORD pid1;
	HANDLE hfile;
	TCHAR argParam[] = L"hello";
	ZeroMemory(&si1, sizeof(si1));
	si1.cb = sizeof(si1);
	ZeroMemory(&pi1, sizeof(pi1));	

	sa.bInheritHandle = TRUE;
	hfile = CreateFile(argv[1], GENERIC_READ, 0,FALSE, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	printf("handle in process1 is %d\n", hfile);

	//Creating process1
	if (!CreateProcess(L"C://Users//Joanna Ruth//Documents//NCRWork//OS//Question7//Debug//Read.exe",NULL, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si1, &pi1)) {

		_tprintf(_T("create process error:%d \n"), GetLastError());
		getchar();
		return false;
	}
	return true;
}