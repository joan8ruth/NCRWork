#include<stdio.h>

void main()
{
	int num;
	printf("Enter the number\n");
	scanf("%x", &num);
	printf("%d\n", num);

	num = num << 2;
	//num = num >> 27;
	printf("%d", num);


}