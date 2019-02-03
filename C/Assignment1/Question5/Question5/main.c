#include <stdio.h>

int main()
{
	int a, num, sum = 0;
	printf("Enter a number");
	scanf("%d", &a);
	num = a;

	while (num) {
		int rev = num % 10;
		sum = sum * 10 + rev;
		num = num / 10;
	}
	if (a == sum) {
		printf("palindrome");
	}
	else {
		printf(" Not palindrome");
	}
	return 0;
}