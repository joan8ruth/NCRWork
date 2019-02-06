#include<stdio.h>

void test(int a);
int reverse(int a, int b, int c, int d);
void rotate(int num);

void main()
{
	int num,C,A,F,E,num2,mask,mask2,feca;
	printf("Enter the number\n");
	scanf("%x", &num);
	//printf("%d\n", num);

	//num = num >> 27;
	//printf("%d", num);
	num2 = num >> 4;
	num2 = num2 << 4;
	E = num ^ num2;
	printf("%d\n", E);

	num2 = num >> 8;
	num2 = num2 << 8;
	mask = num ^ num2;
	mask = mask ^ E;
	F = mask >> 4;
	printf("%d\n", F);

	num2 = num >> 12;
	num2 = num2 << 12;
	mask2 = num ^ num2;
	mask2 = mask2 ^ mask;
	A = mask2 >> 8;
	printf("%d\n", A);

	C = num ^ mask2;
	C = C >> 12;
	printf("%d\n", C);

	test(num);
	feca=reverse(C, A, F, E);
	rotate(feca);
}

void test(int num)
{
	int  E, num2;
	
	num2 = num >> 4;
	num2 = num2 << 4;
	E = num ^ num2;
	if (E >= 7)
		printf("Atleast 3 of last 4 are on\n");
	else
		printf("Atleast 3 of last 4 are not on\n");
	return;
}

int reverse(int C, int A, int F, int E)
{
	int result = 0;
	F = F << 12;
	E = E << 8;
	C = C << 4;
	result = result | F;
	result = result | E;
	result = result | C;
	result = result | A;
	printf("%d\n", result);
	return result;
}

void rotate(int num)
{
	int num2, mask,a,y,x;
	num2 = num >> 12;
	x = num2;
	num2 = num2 << 12;
	a = num ^ num2;
	a = a << 4;
	y = a|x;
	printf("\n%x", y);
	return;

}