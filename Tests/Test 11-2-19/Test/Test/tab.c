#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern FILE *fp;

void tab()
{
	FILE *fp3 = NULL;
	char c;
	fp3 = fopen("fileC", "w");
	do
		{

			c = fgetc(fp);
			if (c == 9)
			{
				fputc('\\', fp3);
				fputc('t', fp3);
			}
			else
				fputc(c, fp3);
		
		} while (c != EOF);
		return;
}
