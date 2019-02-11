#include<stdio.h>
#include<stdlib.h>
extern FILE *fp;

void count()
{
	char c;
	int digit = 0, alpha = 0, space = 0, special = 0;
	
	do
	{

		c = fgetc(fp);
		if (c > 64 && c < 92)
			alpha++;
		else if (c > 96 && c < 124)
			alpha++;
		else if (c == ' ')
			space++;
		else if (c > 47 && c < 58)
			digit++;
		else if (c == 10)
			continue;
		else
			special++;
	} while (c != EOF);
	printf("alphabets:%d\n", alpha);
	printf("spaces:%d\n", space);
	printf("digits:%d\n", digit);
	printf("special:%d\n", special-1);
	return;
}