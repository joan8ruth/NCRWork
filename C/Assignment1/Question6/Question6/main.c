#include<stdio.h>
void main()
{
	int binaryNum[16] = { 0 }, num, i = 0;

	printf("Enter the value of n\n");
	scanf("%d", &num);

	if (num > 0 && num < 33)
	{
		binaryNum[0] = 1;
		i = 15;
		while (num > 0)
		{
			if (num % 2 == 0)
				binaryNum[i] = 0;
			else
				binaryNum[i] = 1;
			i--;
			num = num / 2;
		}

		for (int j = 0; j < 16; j++)
			printf("%d", binaryNum[j]);

	}
}