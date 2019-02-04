#include<stdio.h>
void main()
{
	int binaryNum[10], n,i=0;

	printf("Enter the value of n\n");
	scanf("%d", &n);

	if (n > 0 && n < 33)
	{

		while (n > 0) {

			binaryNum[i] = n % 2;
			n = n / 2;
			i++;
		}



	}
}