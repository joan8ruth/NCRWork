/* Program to terminate a thread via TerminateThread api*/

#include<stdio.h>
#include<Windows.h>
#include<tchar.h>

//This is the thread function for printing 5 values

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

int main(int argc, TCHAR *argv[])
{
	DWORD dwThreadId;
	DWORD  dwExitCode;
	HANDLE hThread;

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
	}

	printf("The parent is waiting for thread to execute...\n");

	WaitForSingleObject(
		hThread,	//hHandle
		INFINITE	//dwMilliseconds
	);

	BOOL retGetexitcodethread = GetExitCodeThread(
		hThread,		//thread handle
		&dwExitCode		//pointer to the exitcode
	);

	if (0 == retGetexitcodethread)
	{
		_tprintf(_T("Error ocuured, GetExitCodeThread: error(%d)"), GetLastError());
		return FALSE;
	}

	else
	{
		//Now we terminate the thread
		BOOL ret = TerminateThread(
			hThread,	//handle Thread
			dwExitCode  //dwExitCode
		);

		//checking if thread terminated or not
		if (0 == ret)
			printf("thread not terminated\n");
		else
			printf("Thread successfully terminated with exit code (%d)\n", dwExitCode);
	}


}