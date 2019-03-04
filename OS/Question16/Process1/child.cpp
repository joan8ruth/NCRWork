/*This is a child process of main.cpp*/

#include<stdio.h>
#include<Windows.h>
#include<tchar.h>

DWORD WINAPI  thread_fun(LPVOID lpParameter)
{
	_tprintf(_T("In thread function"));
	for (int i = 0; i < 10; i++)
	{
		printf("i:(%d)\n", i);
		if (5 == i)
			return i;//exiting with i value
		Sleep(1000);//making the thread sleep for 1 sec
	}
	return 0;
}

int _tmain(int argc, TCHAR *argv[])
{
	int n;
	HANDLE hProcess;
	DWORD priority1,priority2;
	BOOL setPriority;
	DWORD dwThreadId;
	DWORD  dwExitCode;
	HANDLE hThread;

	printf("In child process\n");

	//Getting process handle and printing initial priority
	hProcess = GetCurrentProcess();
	priority1 = GetPriorityClass(hProcess);

	if (priority1)
		_tprintf(TEXT("\n The initial Priority class    = %d\n"), priority1);

	//Setting process priority and printing it
	setPriority = SetPriorityClass( hProcess, 16384);

	priority2 = GetPriorityClass(hProcess);

	if (priority2)
		_tprintf(TEXT("\n The final Priority class    = %d\n"), priority2);

	//Creating a thread
	hThread = CreateThread(
		NULL,			//lpThreadAttributes
		0,				//dwStackSize
		thread_fun,		//lpStartAddress
		NULL,			//lpParameter
		0,				//dwCreationFlags
		&dwThreadId     //lpThreadId
	);

	if (NULL == hThread) {
		printf("Creation of thread is unsuccessful error no:%d\n", GetLastError());
		return false;
	}

	else {
		printf("Thread created successfully\n");
		SetThreadPriority(hThread, BELOW_NORMAL_PRIORITY_CLASS);
	}

	printf("The parent is waiting for thread to execute...\n");

	WaitForSingleObject(
		hThread,	//hHandle
		INFINITE	//dwMilliseconds
	);

	scanf("%d", &n);
	return 1;
}