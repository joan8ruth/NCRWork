/* Write a program to increment a shared integer via Interlocked* functions */

#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<string.h>

volatile LONGLONG counter = 0;

DWORD WINAPI thread_fun(LPVOID lpParam);

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

	if (NULL == hThread1) {
		printf("Creation of thread 1 is unsuccessful error no:%d\n", GetLastError());
		return false;
	}

	else {
		printf("Thread1 created successfully\n");
	}

	hThread2 = CreateThread(
		NULL,			//lpThreadAttributes
		0,				//dwStackSize
		thread_fun,		//lpStartAddress
		NULL,			//lpParameter
		0,				//dwCreationFlags
		&dwThreadId2     //lpThreadId
	);

	if (NULL == hThread2) {
		printf("Creation of thread 2 is unsuccessful error no:%d\n", GetLastError());
		return false;
	}

	else {
		printf("Thread2 created successfully\n");
	}

	WaitForSingleObject(
		hThread1,	//hHandle
		INFINITE	//dwMilliseconds
	);

	WaitForSingleObject(
		hThread2,	//hHandle
		INFINITE	//dwMilliseconds
	);

	if (counter != 2) {
		printf("There is inconsistency in sharing, count is: %d", counter);
	}
	else {
		printf("\nCounter final value is: %d", counter);
	}

	getchar();
	return TRUE;
}

DWORD WINAPI  thread_fun(LPVOID lpParameter)
{
	InterlockedIncrement64(&counter);
	return 0;
}