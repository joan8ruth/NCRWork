#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int i=0, j=0,d;
	char s1[20], s2[20];

	printf("enter string\n");
	scanf("%s", s1);



	while (s1[i] != '\0')
	{
		d = s1[i++];
		if (s1[i] == '-')
		{
			i++;
			while (d < s1[i])
				s2[j++] = d++;
		}
		else
			s2[j++] = d;
	}
	s2[j] = '\0';
	printf("%s", s2);

	scanf("%d", &i);

}