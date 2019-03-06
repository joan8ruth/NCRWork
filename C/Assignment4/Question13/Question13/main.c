#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int i=0, j=0,length,temporary;
	char string1[20],string2[20];
	char* stringPtr1=NULL;

	printf("Enter string\n");
	scanf("%s", string1);

	length = strlen(string1);

	stringPtr1 = (char*)malloc(length * sizeof(char));

	strcpy(stringPtr1, string1);
	
	if (stringPtr1[0] == '-' || stringPtr1[length- 1] == '-')
	{
		printf("Position of hyphen is not valid at beggining and end\n");
	}

	else {

		while (i <= length) {

			
			if ((i + 1) < length && (i + 2) < length && stringPtr1[i + 1] == '-' && stringPtr1[i + 2] == '-') {
				
				printf("No to two consecutive hyphens allowed\n");
				scanf("%d", &i);
				
				return 0;
			}

			

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

	string2[j] = '\0';


	printf("%s", string2);

	
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
	scanf("%d", &i);

	return 0;
}