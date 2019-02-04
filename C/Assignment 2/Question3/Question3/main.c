#include<stdio.h>

int fact(int n);
void main()
{
	int n,r;
	printf("Enter number\n");
	scanf("%d", &n);
	r=fact(n);
	printf("factorial is %d",r);

}

int fact(int n)
{
	if (n == 0)
		return 1;
	else
		return (n*fact(n - 1));

}