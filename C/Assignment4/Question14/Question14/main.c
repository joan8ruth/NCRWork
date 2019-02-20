#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char name[50];
	int  j,l,i,k=0;
	printf("\nEnter a string : ");
	scanf("%s", name);
	l = strlen(name);
	
	for (i = 0; i < l; i++)
	{
		j = (i + 1)%l;
		printf("%c", name[i]);
		while (j != i)
		{
			printf("%c", name[j]);
			j = (j + 1) % l;

		}
		printf("\n");
	}
		
	

	scanf("%d", &j);
	return 0;
}