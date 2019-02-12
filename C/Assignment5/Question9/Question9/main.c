#include<Stdio.h>
#include<stdlib.h>

void main()
{
	FILE *fp = NULL,*fp1=NULL;
	char c;
	int d;
	fp = fopen("fileA", "a+");
	fp1 = fopen("fileB", "a+");

	c = fgetc(fp);
	printf("\n");
	while(c!=EOF) {
		
		printf("%c", c);
		if (c > 96 && c < 123)
		{
			c = c - 32;
			printf("%c", c);
			d = ftell(fp) - 1;
			printf("position is %d\n", d);
			
			fputc(c, fp1);
			d = ftell(fp);
			printf("position is %d\n", d);
		}
		else if(c>64&&c<91)
		{
			c = c + 32;
			printf("%c", c);
			d = ftell(fp) - 1;
			printf("position is %d\n", d);
			
			fputc(c, fp1);

		}
		c = fgetc(fp);

	} 
	printf("\ndone");

}