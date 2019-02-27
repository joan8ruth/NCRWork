/*Program to use Windows API*/
#include<stdio.h>
#include<Windows.h>
#include<string.h>

int main()
{
	CHAR c='A';
	WCHAR wc = L'W';

	CHAR anarr[] = "ANSI";
	WCHAR warr[] = L"WORD";
	BOOL ret;
	int size;
	
	//Checking if Unicode or not

	ret = IsTextUnicode(warr, wcslen(warr), NULL);

	if (ret)
		printf("The text %S is Unicode\n", warr);
	else
		printf("The text %S is not Unicode\n", warr);

	ret = IsTextUnicode(anarr, strlen(anarr), NULL);
	if (ret)
		printf("The text %s is  Unicode\n", anarr);
	else
		printf("The text %s is not Unicode\n", anarr);
	
	//Converting from MultiByte to Wide char

	ret = IsTextUnicode(anarr, strlen(anarr), NULL);
	printf("Before conversion %s is %d\n",anarr,ret);

	size = MultiByteToWideChar(CP_UTF8, 0, anarr, -1, NULL, 0);
	PWSTR wstr = new wchar_t[size];
	MultiByteToWideChar(CP_UTF8, 0, anarr, -1, wstr, size);

	ret = IsTextUnicode(wstr, wcslen(wstr), NULL);
	printf("After conversion %S is %d\n ", wstr, ret);
	delete[] wstr;
	//TEXT("e")

	//Converting from Wide char to MultiByte

	ret = IsTextUnicode(warr, wcslen(warr), NULL);
	printf("Before conversion %S is %d\n", warr, ret);

	size = WideCharToMultiByte(CP_UTF8, 0, warr, -1, NULL, 0, NULL, NULL);
	PSTR wstr1 = new char[size];
	WideCharToMultiByte(CP_UTF8, 0, warr, -1, wstr1, size, NULL, NULL);

	ret = IsTextUnicode(wstr1, strlen(wstr1), NULL);
	printf("After conversion %s is %d\n", wstr1, ret);
	delete[] wstr;

	//Get last error implementation

	size = MultiByteToWideChar(CP_UTF8, 0, anarr, 0, NULL, 0);
	if (size == 0) {
		printf("Error number is %d", GetLastError());
		return -1;
	}

}