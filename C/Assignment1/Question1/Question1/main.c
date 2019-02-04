#include<stdio.h>
//#include "add.c"

extern int addition(int a, int b);
extern int subtraction(int a, int b);
extern int multiplication(int a, int b);
extern int division(int a, int b);

void main()
{
	int a,b,op;
	printf("Enter a and b\n");
	scanf("%d", &a);
	scanf("%d", &b);
	printf("Enter the operator you want\n");
	printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n");
	scanf("%d", &op);
	switch (op) {
		case 1 : printf("%d", addition(a, b));
			     break;
		case 2: printf("%d", subtraction(a, b));
			break;
		case 3: printf("%d", multiplication(a, b));
			break;
		case 4: printf("%d", division(a, b));
			break;

			
	}

//	printf("%d", addition(a,b));
}