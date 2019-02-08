#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int replace(char* p);

void main()
{
	int r;
	char *p;
	p = (char*)malloc(40 * sizeof(char));
	scanf("%[^\n]s\n", p);
	//printf("%s\n", p);
	r=replace(p);

	printf("%s  %d\n", p,r);
}

int replace(char* str)
{
	//printf("in function %s\n", str);
	int l,i,c=0;
	l = strlen(str);
	for (i = 0; i < l; i++)
	{
		if (str[i] == ' ')
		{
			c++;
			str[i] = '-';
		}
	}
	return (c);
}