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

void String2Uint()
{
	char buff[21] = "290826000001";
	unsigned int iNumi = 0;
	unsigned int iNuml = 0;
	unsigned int iNumll = 0;
	iNumi = (unsigned int)atoi(buff);
	iNuml = (unsigned int)atol(buff);
	iNumll = (unsigned int)atoll(buff);

	printf("sizeof(int) is [%d ]\n", sizeof(int));

	printf("iNum is [%d]\t [%u]\t 0x[%02X]\n", iNumi, iNumi, iNumi);
	printf("iNum is [%ld]\t [%lu]\t 0x[%.2X]\n", iNuml, iNuml, iNuml);
	printf("iNum is [%lld]\t [%llu]\t 0x[%.2X]\n", iNumll, iNumll, iNumll);
}


void main()
{
	printf("func Main start\n");

	//ReturnCore();
	String2Uint();

	printf("func Main start\n");
	while (1);
}