#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	char *p;
	char c,s[30];
	int l,i,j=0;
	printf("Enter the string\n");
	scanf("%s", s);
	printf("Enter required character\n");
	scanf(" %c", &c);
	l = strlen(s);
	p = (char*)malloc(l * sizeof(char));
	strcpy(p, s);
	

	for (i = 0; i < l; i++)
	{
		if (p[i] != c)
		{
			p[j] = p[i];
			j++;
		}

	}
	p[j] = '\0';
	printf("The new string is %s\n", p);
	scanf("%d", &i);
}