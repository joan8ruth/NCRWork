/*program to create a process*/

#include<stdio.h>
#include<Windows.h>
#include<tchar.h>

int _tmain(int argc,TCHAR *argv[])
{
	STARTUPINFO si1,si2;
	PROCESS_INFORMATION pi1,pi2;
	SECURITY_ATTRIBUTES sa;
	HANDLE hproc;
	DWORD pid1,pid2;

	ZeroMemory(&si1, sizeof(si1));
	ZeroMemory(&si2, sizeof(si2));
	si1.cb = sizeof(si1);
	si2.cb = sizeof(si2);
	ZeroMemory(&pi1, sizeof(pi1));
	ZeroMemory(&pi2, sizeof(pi2));

	//Commnd line
	if (argc != 3) {
		
		_tprintf(_T("Usage =%s [cmdline]\n"), argv[0]);
		getchar();
		return false;
	}

	//Creating process1
	if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &si1, &pi1)) {

		_tprintf(_T("create process error:%d \n"), GetLastError());
		getchar();
		return false;
	}

	//Creating process2
	if (!CreateProcess(NULL, argv[2], NULL, NULL, FALSE, 0, NULL, NULL, &si2, &pi2)) {

		_tprintf(_T("create process error:%d \n"), GetLastError());
		getchar();
		return false;
	}



	//Printing the process id1 using the function and id from process info structure
	pid1 = GetProcessId(pi1.hProcess);
	printf("The process1  handle is %d and has id %ld and %d\n",pi1.hProcess, pid1,pi1.dwProcessId);
	CloseHandle(pi1.hProcess);

	//Printing the process id2 using the function and id from process info structure
	pid2 = GetProcessId(pi2.hProcess);
	printf("The process2 handle is %d and has id %ld and %d\n", pi2.hProcess, pid2, pi2.dwProcessId);
	CloseHandle(pi2.hProcess);
	
	_tprintf(_T("Done"));
	getchar();
	return TRUE;


}