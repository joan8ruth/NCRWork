#include<stdio.h>

void main()
{
	int  arr[] = { 1, 4, 20, 3, 10, 5 }, req = 33, t,flag=0;
	int i = 0, j = 0, sum = arr[0], len;
	len = sizeof(arr) / sizeof(arr[0]);
	//printf("%d", len);
	if (req == 0)
	{
		for (i = 0; i < len; i++)
		{
			if (arr[0] == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			printf("found");
		else
			printf("not found");
	}
	else
	 {
	 while (i < (len + 1) && j < (len + 1))
	 {
		if ((i >= j) && (j != 0))
		{
			t = i;
			i = j;
			j = t;
		}
		if (arr[0] == req)
		{
			break;
		}
		else if (sum < req)
		{
			if (j == len)
				break;
			else
			{
				j++;
				sum = sum + arr[j];
				//printf("%d\n", sum);
			}
		}
		else if (sum > req)
		{
			if (i == len)
				break;
			else
			{
				sum = sum - arr[i];
				i++;
				//printf("%d\n", sum);

			}
		}
		else if (sum == req)
		{
			break;
		}
	}
	 if (sum == req)
		 printf("found between indices %d and %d",i,j);
	 else
		 printf("not found");
	}
	


}