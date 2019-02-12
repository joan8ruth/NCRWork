#include<stdio.h>
#include<stdlib.h>

struct example1
{
	int d;
	char c;
};

union example2 {
	int n;
	char f;
};

void main()
{
	
	struct example1 e1;
	union example2 e2;
	printf("Size of structure is %d\n", sizeof(e1));
	printf("Size of union is %d", sizeof(e2));


}