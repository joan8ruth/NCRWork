#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{

	FILE *fp,*fp1;
	int d;
	char c[20],s[20],t;
	fp = fopen("fileA", "a+");
	printf("Enter the country\n");
	scanf("%s", s);

	while (fscanf(fp, "%20s", c)==1)
	{
		if (strcmp(strupr(s), strupr(c)) == 0)
		{
			
			fseek(fp, ftell(fp) + 1, SEEK_SET);
			do{
				t = fgetc(fp);
				printf("%c", t);

			} while (t != 10&&t!=EOF);

			break;
		}
		

	}
	

}