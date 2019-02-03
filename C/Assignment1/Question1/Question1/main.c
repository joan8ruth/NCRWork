#include<stdio.h>
#include "add.c"

extern int addition(int a, int b);
void main()
{
	//int c;
	
	printf("%d", addition(4,5));
}