#include <stdio.h>
void main()
{
	unsigned int x = 0x76543210;
	char *c = (char*)&x;

	if (*c == 0x10)
	{
		printf("Underlying architecture is little endian. \n");
	}
	else
	{
		printf("Underlying architecture is big endian. \n");
	}

	
}