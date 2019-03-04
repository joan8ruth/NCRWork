/*program to create an event*/

#include<stdio.h>
#include<Windows.h>

int main()
{
	HANDLE g_hEvent;
	g_hEvent = CreateEvent(NULL, false, false, TEXT("named event"));
	CloseHandle(g_hEvent);

	if (g_hEvent == NULL)
	{
		printf("CreateEvent failed (%d)\n", GetLastError());
		return 0;
	}

	else {
		printf("Event successfully created\n");
	}
	getchar();
	return 1;
}