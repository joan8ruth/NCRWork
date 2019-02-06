#include<stdio.h>
#include<math.h>
#include<string.h>

void btoh(int n);
void htob(char* n);

void main()
{
	int num,op;
	char hex[10];
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
		scanf("%s", hex);
		
		htob(hex);
		break;
	}

}

void btoh(int num)
{
	int n,i=0,j=0,remainder,decimalNumber=0;
	char hex[100];
	
	
	while (num != 0)
	{
		n = num % 10000;
		//printf("%d\n", n);
		while (n != 0)
		{
			remainder = n % 10;

			n /= 10;
			decimalNumber += remainder * pow(2, i);
			++i;
			//printf("%d", decimalNumber);
		}
		if (decimalNumber > 9)
			decimalNumber = decimalNumber + 55;
		else
			decimalNumber = decimalNumber + 48;
		
		//printf("\n%c", decimalNumber);
		num = num / 10000;
		hex[j++] = decimalNumber;
		decimalNumber = 0; i = 0;
	}
	for (i = j-1 ; i >= 0; i--)
	{
		printf("%c", hex[i]);
	}
	 
	
}

void htob(char* hex)
{
	int n,i=0,d,r,j=0,y=3;
	char c;
	int **b;
	n = strlen(hex);
	//printf("%d",n);
	while (i < n)
	{
		c = hex[i];
		d = (int)c;
		printf("%d\n", d);
		i++;
		if (d > 48 && d < 58)
			d = d - 48;
		else
			d = d - 55;
		while (d > 0) {

		}
	}
	

}