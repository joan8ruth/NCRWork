#include<stdio.h>
#include<string.h>
 
void itob(int n, int s);
void itoh(int n, int s);

void main()
{
	
	int n,t,s=0;
	printf("enter the number to convert\n");
	scanf("%ld", &n);
	 itob(n, s);
	 itoh(n, s);
	
	

}

void itob(int n, int s) {
	int binaryNum[10], t = 0, c, max, x=0;
	char r[10];

	int i = 0;
	while (n > 0) {

		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}
	for (t = i - 1; t >=0; t--)
	{
		if (binaryNum[t] == 1)

			r[x++] = '1';
		else
			r[x++] = '0';
	}
	for (t = 0; t < i; t++) {
		printf(" %c", r[t]);
	}
	printf("\n");


}

void itoh(int n,int s)
{
	char hexaDeciNum[100];

	int i = 0;
	while (n != 0)
	{
		int temp = 0;

		temp = n % 16;
		if (temp < 10)
		{
			hexaDeciNum[i] = temp + 48;
			i++;
		}
		else
		{
			hexaDeciNum[i] = temp + 55;
			i++;
		}

		n = n / 16;
	}

	
	for (int j = i - 1; j >= 0; j--)
		printf("%c", hexaDeciNum[j]);
}