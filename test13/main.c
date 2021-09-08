#include <stdio.h>
#include <sys/time.h>
#include <string.h>

long GetLocaTime()
{
	struct timeval start;
	unsigned long diff;
	gettimeofday(&start, NULL);
	return start.tv_usec;
}

// 生成随机数
// iMin 最小值
// iMax 最大值
// iMaxForNum 最大获取次数
int bRandNum( int iMin, int iMax, int iMaxForNum )
{
	time_t t;
	int num;
	int diff = 0; 

	printf("iMin is [%d]\t iMax is [%d]\n", iMin, iMax);
	
	if ( 0 > iMaxForNum )
		return -1;
	srand(GetLocaTime());
	diff = iMax - iMin;
	while( iMaxForNum-- )
	{	
		num  = rand()%(iMax);
		printf("num is [%d]\n", num);
		if( num > iMin)
			return num;

		// 提高命中率
		if ( 0 != diff )
		{
			num += num*((iMin - num)/diff+1);
			if ( num < iMax && num > iMin )
				return num;
		}
	}
	
	// 防止出现bug
	return -1;
}

int GetRandCode(int iType, char *pcRandCode, int iLen )
{
	// 字母表
	char CodeArrt[62] = {
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
	'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
	'u', 'v', 'w', 'x', 'y', 'z',
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X', 'Y', 'Z' 						
	};

	int iRandMaxNum[3] = { 10, 36, 62 };

	int iMaxBit = 0 , iMinBit = 0;
	int iMaxLen;
	time_t t;
	int i,iBit = 0 ;
	char ch;
	int iIsOk = 1;

	// 参数校验
	if ( 0 > iLen )
		return -1;
	
	switch (iType)
 	{
		// 数字
		case 0:
			iMaxBit = iRandMaxNum[0];
			break;		
	
		// 字母
		case 1:
			iMinBit = iRandMaxNum[0];
			iMaxBit = iRandMaxNum[2];
			break;		
		
		// 字母(大)
		case 2:
			iMinBit = iRandMaxNum[1];
			iMaxBit = iRandMaxNum[2];
			break;		

		// 字母(小)
		case 3:
			iMinBit = iRandMaxNum[0];
			iMaxBit = iRandMaxNum[1];
			break;		

		// 字母 + 数字
		case 4:
			iMaxBit = iRandMaxNum[2];
			break;		

		// 字母(大) + 数字
		case 5:
			iMaxBit = iRandMaxNum[2];
			break;		

		// 字母(小) + 数字
		case 6:
			iMaxBit = iRandMaxNum[1];
			break;		
		
		default:
			return -2;
	}

	iMaxLen = iLen;
	pcRandCode[iMaxLen] = '\0';
	while( --iMaxLen >= 0 )
	{	
		iBit = bRandNum( iMinBit, iMaxBit, 10 );
		if ( 5 == iType && iBit < iRandMaxNum[1] && iBit >= iRandMaxNum[0] )
			iBit += 26;

		pcRandCode[iMaxLen] = CodeArrt[iBit];
	}
	
	// 检查
	if ( iIsOk )
	{
		iIsOk = 0;
		while( --iLen > 0 )
		{
			if( pcRandCode[iLen] != '\0')
				iIsOk = 1;		
		}
	}

	return iIsOk == 0 ? (-1) : (0); 
}

void main()
{
	char buff[7];
	int iRet = 0;		
	memset( buff, 0x00, sizeof(buff));
	iRet = GetRandCode( 5, buff, 6);
	if ( iRet )
	{
		printf( "err! iRet is [%d]", iRet);
	}
		
	printf("buff is [%s]\n", buff);

}
