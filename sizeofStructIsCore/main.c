#include <stdio.h>
#include <string.h>

typedef struct tian {
	int a;
	char sStr1[10];
	char cStatus;
}stTian;

int main()
{
	stTian tmp[64];
	printf("1111\n");

	memset( &tmp, 0x00 , sizeof(tmp));

	printf("2222\n");

	printf( "%d\n", sizeof(tmp));
	
}
