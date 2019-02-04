#include<stdio.h>
#include<math.h>

void rotate(int n, int b);
void main()
{
	int n, b;
	printf("Enter n and b\n");
	scanf("%d", &n);
	scanf("%d", &b);

	 rotate(n, b);

}

void rotate(int n, int b)
{
	long int mul, num, num2, res, count;
	mul = pow(10, b);
	num = n % mul;
	num2 = n / mul;
	count = log10(num2) + 1;
	res = num * pow(10, count) + num2;
	printf("The rotated result is %d", res);

	

}