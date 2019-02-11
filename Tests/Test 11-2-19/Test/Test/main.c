#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void count();
void comment();
void rotate();
void tab();

extern FILE *fp = NULL;
void main()
{
	
	char contents[100];
	char c;
	int d,i=0;
	
	fp=fopen("fileA", "a+");
	if (fp == NULL)
		printf("fail\n");
	
	
	printf("\n");
	printf("1.Count the number of digits,alphabets,spaces and special characters\n");
	printf("2.Remove all the single and multiline comments\n");
	printf("3.Find a matching word and rotate it\n");
	printf("4.Replace all tabs with /\t\n");
	scanf("%d", &d);
	switch (d)
	{
		case 1: count();
				break;
		case 2: comment();
			    break;
		case 3: rotate();
			    break;
		case 4: tab();
			    break;
	}
	

		
	
}