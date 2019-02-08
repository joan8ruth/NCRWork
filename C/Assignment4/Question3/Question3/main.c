#include<stdio.h>
#include<string.h>
void main()
{
	char * s[] = { "we will teach you how to" , "Move a mountain","Level a building","Erase the past","Make a million", };
		
	int e = 0,l1,l2,i,j;
	l1 = sizeof(s) / sizeof(char*);
	//printf("%c", s[0][1]);
	for (i = 0; i < l1; i++)
	{
		l2 = strlen(s[i]);
		//printf("%d\n", l2);
		for (j = 0; j < l2; j++)
		{
			if (s[i][j] == 'e' || s[i][j] == 'E')
				e++;
		}
		e--;
	}
	printf("%d", e);

}