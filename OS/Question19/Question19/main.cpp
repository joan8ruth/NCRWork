/*Write a program to modify shared variable between two threads guarded by critical section*/

#include<stdio.h>
#include<Windows.h>
#include<tchar.h>

CRITICAL_SECTION cs;
const int Counter = 20;
int sum = 0;

DWORD WINAPI  thread_fun1(LPVOID lpParameter)
{
	EnterCriticalSection(&cs);
	sum = 0;
	for (int i = 0; i <= Counter; i++) {
		printf("In thread1 sum:%d\n", sum);
		sum = sum + 1;
	}
	LeaveCriticalSection(&cs);
	return 0;
}

DWORD WINAPI  thread_fun2(LPVOID lpParameter)
{
	EnterCriticalSection(&cs);
	sum = 0;
	for (int i = 0; i <= Counter; i++) {
		printf("In thread2 sum:%d\n", sum);
		sum = sum + 1;
	}
	LeaveCriticalSection(&cs);
	return 0;
}

int main(int argc, TCHAR *argv[])
{

	DWORD dwThreadId1, dwThreadId2;
	HANDLE hThread1, hThread2;

	if (!InitializeCriticalSectionAndSpinCount(&cs,
		0x00000400))
		return 0;

	hThread1 = CreateThread(
		NULL,			//lpThreadAttributes
		0,				//dwStackSize
		thread_fun1,		//lpStartAddress
		NULL,			//lpParameter
		0,				//dwCreationFlags
		&dwThreadId1     //lpThreadId
	);

	if (NULL == hThread1) {
		printf("Creation of thread 1 is unsuccessful error no:%d\n", GetLastError());
		return 0;
	}

	else {
		printf("Thread1 created successfully\n");
	}

	hThread2 = CreateThread(
		NULL,			//lpThreadAttributes
		0,				//dwStackSize
		thread_fun2,	//lpStartAddress
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

	DeleteCriticalSection(&cs);
	return 1;
}
