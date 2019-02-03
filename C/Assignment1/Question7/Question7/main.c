#include<stdio.h>
void main()
{
	int num = 0, min = 1000, max = 0, sum = 0,n;
	do {
		
		scanf("%d",&n);
		num++;
		if (n <= 0)
			break;
		if (n < min)
			min = n;
		if (n > max)
			max = n;
		sum = sum + n;

	} while (n > 0);
	num--;
	printf("Totla number os values given is %d\n",num);
	printf("Minimum value is %d\n",min);
	printf("Maximum value is %d\n",max);
	printf("average is %d",(sum/num));


}