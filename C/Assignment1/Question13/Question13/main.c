#include<stdio.h>

int invertponwards(int n, int p, int b);

void main() {

	int result, n, p, b;
	printf("enter the values of n, p, b\n");
	scanf("%d", &n);
	scanf("%d", &p);
	scanf("%d", &b);
	result = invertponwards(n, p, b);

}

int invertponwards(int n, int p, int b)
{
	int binaryNum[10],t=0,c,max,x;

	int i = 0;
	while (n > 0) {

		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}
	
	for (c = 0; c < i; c++) {
		printf("%d", binaryNum[c]);
	}
	printf("\n");
	
	max = p+b;
	c = p + 1;
	if (max < i) {
		while(t<b)
		{
			
				if (binaryNum[c] == 1)
					binaryNum[c] = 0;
				else
					binaryNum[c] = 1;
				c++;
				t++;
			
		}
	}
	else
		printf("enter other values for p and b");

	for (c = i-1; c >-1; c--) {
		printf("%d", binaryNum[c]);
	}

	x = 0;
	for (c = i - 1; c >= 0; c--)
	{
		x = x * 2 + binaryNum[I];
	}
	return x;
	

}