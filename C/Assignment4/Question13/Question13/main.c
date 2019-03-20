#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
	int i=0, j=0,length,temporary,flag=0;
	char string1[27],string2[50];
	char* stringPtr1=NULL;

	printf("Enter string\n");
	scanf("%s", string1);

	length = strlen(string1);

	stringPtr1 = (char*)malloc(length * sizeof(char));

	strcpy(stringPtr1, string1);
	
	//Checking if hyphens are at the beginning or end
	if (stringPtr1[0] == '-' || stringPtr1[length- 1] == '-')
	{
		printf("Position of hyphen is not valid at beginning or end\n");
		return -1;
	}

	else {

		while (i <= length) {
	
				flag = 0;

				if ((i + 1) < length && (i + 2) < length) {
					flag = 1;
				}

				//Checking  if non alphanumeric on either side of the hyphen
				if (flag && !isalnum(stringPtr1[i]) && !isalnum(stringPtr1[i+2]) && stringPtr1[i] != '-') {
					printf("Cannot expand non alphabets and non digits\n");
					scanf("%d", &i);
					return 0;
				}

				//Checking for consecutive hyphens
				else if (flag && stringPtr1[i + 1] == '-' && stringPtr1[i + 2] == '-') {
					printf("Error: No to two consecutive hyphens allowed\n");
					//getchar();
					scanf("%d", &i);

					return 0;
				}

				//Checking if either side of hyphen has an alphabet and digit together
				else if (flag && isalpha(stringPtr1[i]) && isdigit(stringPtr1[i + 2])) {
					printf("Error: Cannot expand alpha to digit\n");
					scanf("%d", &i);

					return 0;

				}

				//Checking if either side of hyphen has an alphabet and digit together
				else if (flag && isdigit(stringPtr1[i]) && isalpha(stringPtr1[i + 2])) {
					printf("Error: Cannot expand digit to alpha\n");
					scanf("%d", &i);

					return 0;

				}

				//Checking if either side of hyphen has a ascii values that are equal or if left is greater than right
				else if (flag && stringPtr1[i]>=stringPtr1[i + 2]) {
					printf("Error: Cannot expand \n");
					scanf("%d", &i);

					return 0;

				}
		
				//Expansion of shorthand
				else {
				
					temporary = stringPtr1[i++];

					if (stringPtr1[i] == '-') {
						i++;
						while (temporary < stringPtr1[i])
							string2[j++] = temporary++;
					}

					else
						string2[j++] = temporary;
				}

		}
	}

	//Appending null character at end of final expanded string
	string2[j] = '\0';

	printf("%s", string2);

	scanf("%d", &i);
	//getchar();
	return 0;
}

	//free(stringPtr1);
	/*else {
		while (s1[i] != '\0')
		{
			temporary = s1[i++];
			if (s1[i] == '-')
			{
				i++;
				while (temporary < s1[i])
					s2[j++] = temporary++;
			}
			else
				s2[j++] = temporary;
		}
		s2[j] = '\0';
	}
	cout << s2;*/
	//printf("%s", s2);

	
	//free(stringPtr1);
	