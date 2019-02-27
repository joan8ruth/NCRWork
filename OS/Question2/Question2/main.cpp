#include <windows.h>
#include <stdio.h>

constexpr auto INFO_BUFFER_SIZE = 32767;

int main(int argc, char** argv)
{
	LPWSTR *szArglist;
	int nArgs;
	int i, bufCharCount;
	TCHAR  infoBuf[INFO_BUFFER_SIZE];
	const wchar_t* path = TEXT("%SYSTEMROOT%");

	//Method using CommandLineToArgvW
	szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);

	if (NULL == szArglist)
	{
		wprintf(L"CommandLineToArgvW failed\n");
		return 0;
	}
	else 
		for (i = 0; i < nArgs; i++)
		printf("%d: %ws\n", i, szArglist[i]);

	//Printing environment strings
	bufCharCount = ExpandEnvironmentStrings(path, infoBuf,
		INFO_BUFFER_SIZE);
	if (bufCharCount > INFO_BUFFER_SIZE)
		wprintf(L"\n\t Buffer too small to expand: \"%s\n");
		
	else
		wprintf(L"\n   %s", infoBuf);
	return 1;
}