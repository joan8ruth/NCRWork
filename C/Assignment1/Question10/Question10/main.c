#include <stdio.h>

int main()
{
	int num, sum = 0;
	printf("Enter your number\n");
	scanf("%d", &num);
	int b = num;

	while (num) {
		int a = num % 10;
		sum = sum + a;
		num = num / 10;

	}

	printf("The sum of digits is %d", sum);



	return 0;
}