#include<stdio.h>
#include<string.h>
void main()
{
	char c[80];
	int alphabet = 0, digit = 0, blank = 0, tab = 0,i;
	printf("Enter the characters\n");

	scanf_s("%[^\n]s", c,sizeof(c));
	//printf("Entered the characters %c\n",c[1]);
	//j = strlen(c);
	//printf("%d\n",j);

	for (i = 0; i < strlen(c); i++)
	{
		if ((c[i] >= 65 && c[i] <= 91) || (c[i] >= 97 && c[i] <= 122))
		{
			alphabet++;
		}
		else if (c[i] >= 48 && c[i] <= 57)
		{
			digit++;
		}
		else if (c[i] == ' ')
		{
			blank++;
		}
		else
		{
			tab++;
		}
	}

	printf("Number of alphabets are : %d\n", alphabet);
	printf("Number of digits are : %d\n", digit);
	printf("Number of blanks are : %d\n", blank);
	printf("Number of tabs are: %d\n", tab);


}