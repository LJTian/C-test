#include<stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
	size_t i;
	for (i = 0 ; i < len; i++)
		printf("%.2X",start[i]);
	printf("\n");
}

void show_int(int x)
{
	show_bytes((byte_pointer) &x,sizeof(int));
}

void show_float(float x)
{
	show_bytes((byte_pointer) &x,sizeof(float));
}

void show_pointer(void *x)
{
	show_bytes((byte_pointer) &x,sizeof(void *));
}

void main(void)
{
	printf("start~~~~~~~~~~~\n");

	int iVal = 12345;
	float fVal = (float)iVal;
	int *pVal = &iVal;
	show_int(iVal);
	show_float(fVal);
	show_pointer(pVal);
}
