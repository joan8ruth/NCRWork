/*program to create a thread in suspended state*/

#include<stdio.h>
#include<Windows.h>
#include<tchar.h>

DWORD WINAPI  thread_fun(LPVOID lpParameter)
{
	_tprintf(_T("In thread function\n"));
	Sleep(1000);

	for (int i = 1; i <= 1000; i++)
	{
		printf("%d\n", i);//printing 1000 numbers
		Sleep(100);
	}

	return 0;
}

int main(int argc, TCHAR *argv[])
{
	DWORD dwThreadId;
	DWORD  dwExitCode;
	HANDLE hThread;

	hThread = CreateThread(
		NULL,				//lpThreadAttributes
		0,					//dwStackSize
		thread_fun,			//lpStartAddress
		NULL,				//lpParameter
		CREATE_SUSPENDED,	//dwCreationFlags
		&dwThreadId			//lpThreadId
	);

	if (NULL == hThread) {
		printf("Creation of thread is unsuccessful error no:%d\n", GetLastError());
		return false;
	}

	else {
		printf("Thread created successfully\n");
	}

	printf("Now in suspended state\n");

	Sleep(5000);

	printf("resuming the thread....\n");
	DWORD status = ResumeThread(hThread);

	//waiting for thread to execute
	printf("parent waiting for thread to execute..\n");
	WaitForSingleObject(
		hThread,	//hHandle
		INFINITE	//dwMilliseconds
	);

	return 0;

}