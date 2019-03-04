/*Write a program to increment the value of a shared integer by two threads of the same process. 
Print the final value of shared integer in the process’s primary thread*/

#include<stdio.h>
#include<Windows.h>
#include<tchar.h>

static int x=1;

//This is the thread function for printing 5 values

DWORD WINAPI  thread_fun(LPVOID lpParameter)
{
	_tprintf(_T("In thread function"));
	x++;
	printf("x value is %d\n",x);
	return 0;
}

int main(int argc, TCHAR *argv[])
{
	DWORD dwThreadId1, dwThreadId2;
	DWORD  dwExitCode;
	HANDLE hThread1, hThread2;

	hThread1 = CreateThread(
		NULL,			//lpThreadAttributes
		0,				//dwStackSize
		thread_fun,		//lpStartAddress
		NULL,			//lpParameter
		0,				//dwCreationFlags
		&dwThreadId1     //lpThreadId
	);

	hThread2 = CreateThread(
		NULL,			//lpThreadAttributes
		0,				//dwStackSize
		thread_fun,		//lpStartAddress
		NULL,			//lpParameter
		0,				//dwCreationFlags
		&dwThreadId2     //lpThreadId
	);

	if (NULL == hThread1) {
		printf("Creation of thread 1 is unsuccessful error no:%d\n", GetLastError());
		return false;
	}

	else {
		printf("Thread1 created successfully\n");
	}

	if (NULL == hThread2) {
		printf("Creation of thread 2 is unsuccessful error no:%d\n", GetLastError());
		return false;
	}

	else {
		printf("Thread2 created successfully\n");
	}

	printf("The parent is waiting for thread to execute...\n");

	WaitForSingleObject(
		hThread1,	//hHandle
		INFINITE	//dwMilliseconds
	);

	WaitForSingleObject(
		hThread2,	//hHandle
		INFINITE	//dwMilliseconds
	);

	printf("final value of x in main process is %d\n", x);

	return 0;

}