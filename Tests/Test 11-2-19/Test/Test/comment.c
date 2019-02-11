#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern FILE *fp;

void comment()
{
	int i=0,j,l;
	FILE *fp2=NULL;
	char text[100],c,c1,c2;
	fp2 = fopen("fileB", "w");
	
	do
	{
		c = fgetc(fp);
		text[i++] = c;
		
	} while (c != EOF);
	text[i] = '\0';
	
	l = strlen(text);
	printf("%s", text);
	printf("\n");
	for (i = 0; i < l; i++)
	{
		if (i != l - 2) {
			c1 = text[i];
			c2 = text[i + 1];
			if (c1 == 47 &&c2 == 47)
			{
				j = i;
				do {
					c1 = text[j];
					text[j++] = ' ';
				} while (c1 != 10);
			}
			
		}
		

	}
	printf("%s", text);
	fputs(text, fp2);
	
	
	return;
}