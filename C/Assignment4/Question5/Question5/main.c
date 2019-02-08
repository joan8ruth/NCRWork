#include<stdio.h>
#include<string.h>
void main()
{
	char s[30],i,l,d;
	printf("enter the string\n");
	scanf("%[^\n]s", s);
	//printf(" the string %s\n",s);
	l = strlen(s);
	for (i = 0; i < l; i++)
	{
		d = (int)s[i];
		if (d > 64 && d < 91)
		{
			d = d + 32;
			s[i] = (char)d;
		}
		else if (d > 96 && d < 123)
		{
			d = d - 32;
			s[i] = (char)d;
		}
	}
	printf(" the string %s\n", s);
}