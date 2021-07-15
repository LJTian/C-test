#include<stdio.h>
#include<string.h>

int ReturnCore()
{
	char buff[] = "1234";
	char buff1[8];
	char buff2[] = "1234";
	
	printf("func ReturnCore start\n");

	memcpy(buff, "12345678", 9);

	printf("func ReturnCore end\n");
	
	return 0;
}


void main()
{
	printf("func Main start\n");

	ReturnCore();

	printf("func Main start\n");
}
