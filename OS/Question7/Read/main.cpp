/*A program to read a file*/

#include<stdio.h>
#include<Windows.h>
#include<tchar.h>

#define BUFFSIZE 100

int _tmain(int argc, LPTSTR argv[])
{
	TCHAR buffer[BUFFSIZE] = { 0 };
	BOOL ret;
	DWORD nbr;
	int i;
	
	printf("In read file\n");
	ret = ReadFile(argv[1], buffer, BUFFSIZE, &nbr, NULL);

	if (0 == ret) {
		_tprintf(_T("Can't read file %s Error:%d"), argv[1], GetLastError());
		scanf("%d", &i);
		return FALSE;
	}

	else {
		_tprintf(_T("Text from %s is :\n%S"), argv[1], buffer);
		scanf("%d", &i);
		return TRUE;
	}
	scanf("%d", &i);
	getchar();
	return 1;
}