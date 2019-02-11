#include<stdio.h>
#include<string.h>

void reverse(char*);

void main()
{
	char a[] = "Hello";
	reverse(a);
	
}

void reverse(char *str)
{
	if (*str)
	{
		reverse(str + 1);
		printf("%c", *str);
	}
}


