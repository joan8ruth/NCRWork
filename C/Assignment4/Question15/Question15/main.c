#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void copyString(char* s1, char* s2);
int lengthOfString(char* s);
void reverseString(char* s);

//Returns length of string
int lengthOfString(char* s) {
	int n=0;
	
	while (s[n] != '\0') {
		n++;
	}
	return n;
}

//Reversing the string
void reverseString(char* s)  
{
	char temp;
	int i, j,length;

	length = lengthOfString(s);
	
	for (int i = 0; i <( length/2 ); i++)
	{
		temp = s[i];
		s[i] = s[length - i - 1];
		s[length - i - 1] = temp;

	}
}


//Used to copy contents from string2 to string1
void copyString(char* s1,char* s2) {

	int length = lengthOfString(s2);
	int i;
	for ( i = 0; i <= length; i++)
		s1[i] = s2[i];
	s1[i] = '\0';
}

//Function to concatenate two strings and return concatenated strings
char* stringConCat(char* string1, char* string2)
{
	char* string = NULL;;
	int i = 0, j = 0, length1, length2,length;

	length1 = lengthOfString(string1);
	length2 = lengthOfString(string2);
	length = length1 + length2;


	string = (char*)malloc((length) * sizeof(char));
	if (string == NULL) {
		printf("Error\n");
		return NULL;
	}
	else {

		for (i = 0; string1[i]!='\0'; i++)
			string[i] = string1[i];
		while (string2[j] != '\0')
		{

			string[i] = string2[j++];
			i++;
		}
		string[i] = '\0';
	}
	
	return string;

}

//Compares two strings, if they are the same return 1 else return 0
int strComp(char* st1, char* st2)
{
	if (lengthOfString(st1) != lengthOfString(st2))
		return 0;
	else
	{
		int i = 0;
		while (st1[i] != '\0')
		{
			if (st1[i] != st2[i])
				return 0;
			i++;
		}
		return 1;

	}

}

int main() {

	char string1[20], string2[20], choice;//, string4[20], choice;
	char* stringPtr1 = NULL,*conCat=NULL,*stringPtr2=NULL;
	int i, j,length,menu,length2;


	
		do {

			printf("Choose your menu option :1.Reverse 2.Concatenate 3.Compare\n");
			scanf("%d", &menu);
			switch (menu) {
			case 1:printf("Enter the string to reverse\n");
					scanf("%s",string1);
					length = lengthOfString(string1);
					stringPtr1 = (char *)malloc(length * sizeof(char));
					copyString(stringPtr1, string1);
					reverseString(stringPtr1);
					printf("reversed is %s\n", stringPtr1);
					break;
			case 2:printf("Enter initial string\n");
				scanf("%s", string1);
				printf("Enter second string string\n");
				scanf("%s", string2);
				conCat= stringConCat(string1, string2);
				printf("Concatenated string is %s\n", conCat);
				break;

			case 3:printf("Enter initial string\n");
				scanf("%s", string1);
				printf("Enter second string string\n");
				scanf("%s", string2);
				if (strComp(string1, string2)) {
					printf("%s is equal to %s\n", string1, string2);
				}
				else {
					printf("%s is not equal to %s\n", string1, string2);
				}
				break;
			}
			printf("do you want to continue y/n?\n");
			scanf(" %c",&choice);

		} while (choice == 'y' || choice == 'Y');

	

	free(stringPtr1);
	getchar();
	return 0;
}