#include<stdio.h>
#include<stdlib.h>

extern FILE *fp;

void rotate()
{
	char *text;
	char buff[100];
	text = fgets(buff, 10, fp);
	printf("%s", text);
	

}