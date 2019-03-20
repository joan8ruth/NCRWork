
#include <ctype.h>
#include <stdio.h>
#include<stdlib.h>

#define SIZE 50 

char s[SIZE];
int top = -1; 
char pop();
int flag = 0;

void push(char elem) {
	s[++top] = elem;
	
	/*if (top!=-1 && s[top] >= 0 && s[top] <= 9) {
		s[top] *= 10;
		s[top] += elem;
		s[top] = ' ';
	}
	else {
		s[++top] = elem;
	}*/
	
}


char pop() {
	return (s[top--]);
}

//This function gives precedence of an operator
int pr(char elem) {
	switch (elem) {
	case '#':
		return 0;
	case '(':
		return 1;
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	}
}

void infix_to_postfix(char *infix, char *postfix) {
	char ch, elem;//ch is element being inspected, elem is the element popped from stack, s is the stack
	int i = 0, k = 0;

	push('#');

	while ((ch = infix[i++]) != '\n') {
		if (ch == '(')
			push(ch);
		else if (isdigit(ch))
			postfix[k++] = ch;
		else if (ch == ')') {
			while (s[top] != '(')
				postfix[k++] = pop();
			elem = pop(); 
		}
		else { 
			while (pr(s[top]) >= pr(ch))
				postfix[k++] = pop();
			push(ch);
		}
	}

	while (s[top] != '#') 
		postfix[k++] = pop();

	postfix[k] = 0; 
}


int eval_postfix(char *postfix) {
	char ch;             //ch is the element being inspected
	int i = 0, op1, op2; //op1 and op2 are the two operands to be operated on
	while ((ch = postfix[i++]) != 0) {
		if (isdigit(ch))
			push(ch - '0'); 
	
		else { 
		
			op2 = pop();
			op1 = pop();

			switch (ch) {
			case '+': push(op1 + op2);
				break;
			case '-': push(op1 - op2);
				break;
			case '*': push(op1*op2);
				break;
			case '/': push(op1 / op2);
				break;
			}
		}
	}
	return s[top];
}

void main() { 

	char infix[50], pofx[50];
	printf("\Enter the calculation expression\n ");
		(infix, 50, stdin);

	//scanf("%s", infix);
	infix_to_postfix(infix, pofx);

	top = -1;
	printf("\nResult of evaluation is : %d", eval_postfix(pofx));
}


//#include<stdio.h>
//
//
//void main()
//{
//	int a,b,op;
//	printf("Enter a and b\n");
//	scanf("%d", &a);
//	scanf("%d", &b);
//	printf("Enter the operator you want\n");
//	printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n");
//	scanf("%d", &op);
//	switch (op) {
//		case 1 : printf("%d", addition(a, b));
//			     break;
//		case 2: printf("%d", subtraction(a, b));
//				break;
//		case 3: printf("%d", multiplication(a, b));
//				break;
//		case 4: printf("%d", division(a, b));
//				break;
//
//			
//	}
//
//	printf("%d", addition(a,b));
//}