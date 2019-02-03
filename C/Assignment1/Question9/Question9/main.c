#include<stdio.h>

void main()
{
	int n,i,j,s;
	printf("enter the number of rows\n");
	scanf_s("%d", &n, sizeof(n));

	for (i = 1; i <= n; i++)
	{
		for (s = 0; s < (n - i); s++)
			printf(" ");
		if (i == 1)
		{
			printf("1\n");
			continue;
		}
		else
		{
			j = i;
			while (j != 0)
			{
				printf("%d", j--);
			}
			j = 2;

			while (j <= i)
			{
				printf("%d", j++);
			}
			printf("\n");
		}

	}

}