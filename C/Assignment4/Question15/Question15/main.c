#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void copyString(char* s1, char* s2);
int lengthOfString(char* s);
void reverseString(char* s);


int lengthOfString(char* s) {
	int n=0;
	
	while (s[n] != '\0') {
		n++;
	}
	return n;
}

//Reversing string
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

void copyString(char* s1,char* s2) {

	int length = lengthOfString(s2);
	int i;
	for ( i = 0; i <= length; i++)
		s1[i] = s2[i];
	s1[i] = '\0';
}

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

	char string1[50],string2[50];
	char* stringPtr1 = NULL,*conCat=NULL;
	int i, j,length;

	printf("Enter your string\n");
	scanf("%s", string1);

	length = lengthOfString(string1);
	

	stringPtr1 = (char *)malloc(length * sizeof(char));
	copyString(stringPtr1, string1);

	if (stringPtr1 == NULL) {
		printf("Error:Memory not allocated\n");
		return 0;
	}

	else {

		printf("Enter string to concactenate\n");
		scanf("%s", string2);

		conCat=stringConCat(stringPtr1, string2);
		printf("After concatenation %s\n", conCat);

		length = lengthOfString(stringPtr1);
		reverseString(stringPtr1);
		printf("reversed is %s\n", stringPtr1);

		if (strComp(stringPtr1, conCat)) {
			printf("%s is equal to %s\n", stringPtr1,conCat);
		}
		else {
			printf("%s is not equal to %s\n", stringPtr1,conCat);
		}
	}

	getchar();

}