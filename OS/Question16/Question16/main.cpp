/*Write a program to create a child process with HIGH priority class.
Change the priority of child process to BELOW_NORMAL from within child process. 
Also create a thread within the child process with LOWEST relative priority*/

#include<stdio.h>
#include<Windows.h>
#include<tchar.h>

int _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO si1;
	PROCESS_INFORMATION pi1;

	ZeroMemory(&si1, sizeof(si1));
	si1.cb = sizeof(si1);
	ZeroMemory(&pi1, sizeof(pi1));

	
	if (!CreateProcess(L"C://Users//Joanna Ruth//Documents//NCRWork//OS//Question16//Debug//Process1.exe", NULL, NULL, NULL, TRUE, HIGH_PRIORITY_CLASS, NULL, NULL, &si1, &pi1)) {

		_tprintf(_T("create process error:%d \n"), GetLastError());
		getchar();
		return false;
	}


}