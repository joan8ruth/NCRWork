#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{

	char **p;
	char *temp;
	char s[50];
	int n,i,j,len;
	printf("Enter how many strings\n");
	scanf("%d", &n);

	p = (char**)malloc(n * sizeof(char*));

	printf("Enter the strings\n");
	for (i = 0; i < n; i++)
	{
		scanf("%s", s);
		len = strlen(s);
		p[i]=(char*)malloc(len*sizeof(char));
		strcpy(p[i], s);
	}
	//temp = p[0][0];
	//printf("First char is %c", temp);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n-i; j++)
		{
			
			if (p[j][0] > p[j + 1][0])
			{
				
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;

			}
		}

	}

	printf("After sorting\n");

	for (i = 0; i < n; i++)
	{
		printf("%s\n", p[i]);
	}
	scanf("%d", n);
}