#include <stdio.h>
#include <string.h>

/* 从字符串中根据分隔符获取对应域的值 */
int GetValueOfDomain(char *psOldBuff, char cSep, int domain, char *psOutBuff )
{
	char *pTmep = NULL;
	char *pStart = NULL;
	char *pEnd = NULL;
	int iDomain = 0 ;
	int iRet = -1;

	if ( domain	< 0 )
		return iRet;

	pTmep = psOldBuff;
	pStart = pTmep;
	pEnd = pTmep;
	
	while( 1 )
	{
		if ( *pTmep == '\0' )
			break;
		if( *pTmep == cSep )
		{
			
			pStart = pEnd;
			pEnd = pTmep + 1;
			iDomain++;
		}
			
		if( iDomain == domain )
		{
			iRet = 0;
			break;
		}
		pTmep++;
	}
	
	if ( !iRet )
	{
		memcpy( psOutBuff, pStart, pEnd - pStart );
		psOutBuff[pEnd - pStart - 1] = '\0';
	}

	return iRet;
}

void main(void)
{
	char tmpbuff[] = "01,,,,,,,,,10";
	char outbuff[1024];
	printf( "tmpbuff is [%s]\n", tmpbuff);
	memset( outbuff, 0x00, 1024);
	if (GetValueOfDomain(tmpbuff, ',',2,outbuff))
	{
		printf("失败!\n");
	}
	else
	{
		printf("outbuff is [%s]", outbuff);
	}	
}
