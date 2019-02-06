#include<stdio.h>

void btoh(int n);
void htob(int n);

void main()
{
	int num,op;
	printf("1.Binary to Hexa\n");
	printf("2.Hexa to Binary\n");
	scanf("%d", &op);
	switch (op)
	{
	case 1: printf("Enter your binary value\n");
		scanf("%d", &num);
		btoh(num);
		break;

	case 2: printf("Enter your Hexa value\n");
		scanf("%x", &num);
		htob(num);
		break;
	}

}

void btoh(int num)
{
	int n,n1=0, n2, n3,i=2;
	n2 = num;
	n = num;
	while (num != 0)
	{

	}
	 
	printf("%x\n", n1);
}

void htob(int num)
{
	printf("..");
}