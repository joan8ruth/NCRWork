#include<stdio.h>
#include<stdlib.h>

void main()
{
	FILE *fp = NULL;
	char c;
	fp = fopen("fileA", "a+");

	
	do {
		c = fgetc(fp);
		printf("%c", c);

	} while (c != EOF);

}