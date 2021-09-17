#include<stdio.h>
#include<string.h>

typedef struct tian{
	int a;
	char sStr1[10];
	char cStatus;
}stTian;

int func1(){
	return 2;
}

void main(void)
{
	stTian tmp[func1()];
	stTian *ptmp;
	int i = 0;
	i = func1();
	char strTmp[i];
	memset( tmp, 0x00 , 2*sizeof(stTian));
	tmp[0].a = 1;
	memcpy(tmp[0].sStr1,"tmp1",strlen("tmp1"));
	tmp[0].cStatus = 'O';

	tmp[1].a = 2;
	memcpy(tmp[1].sStr1,"tmp2",strlen("tmp2"));
	tmp[1].cStatus = 'I';

	printf("strTmp sizeof is [%d]\n", sizeof(strTmp));
	ptmp = tmp;
	ptmp ++;
	printf("第二个元素的值 :\n\t a : [%d]\n\t sStr1 : [%s]\n\t cStatus : [%c]\n",
		 ptmp->a, ptmp->sStr1, ptmp->cStatus);
}
