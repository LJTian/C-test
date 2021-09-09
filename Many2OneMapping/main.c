#include <stdio.h>
#include <string.h>


/*
 * *    函数名称 BackMapp
 * *    入    参 pBuff：待解析字符串 caInBuff:需要映射的返回码 caFirstSeparator：第一分割符 caSecondlySeparator：第二分割符 
 * *    出    参 pRetBuff：返回结果
 * *    返 回 值 0：成功 -1：失败 
 * *    功    能 根据配置文件解析出对应的返回码
 * */
int BackMapp( char* const pcBuff,
    char* const pcInBuff,
    char* pcRetBuff ,
    char* const pcFirstSeparator ,
    char* const pcSecondlySeparator)
{
    char caBigBuff[1024] = {0x00};
    char caOldBuff[1024] = {0x00};
    char caNewBuff[1024] = {0x00};
    char caInBuff[1024] = {0x00};
    char caOutbuff[1024] = {0x00};
    char caFirstSeparator[1024] = {0x00};
    char caSecondlySeparator[1024] = {0x00};
    char *pStrtok = NULL;
    char *pStrstr = NULL;

	// 入参校验
    if( !strlen(pcBuff)||
        !strlen(pcInBuff)||
        !strlen(pcFirstSeparator)||
        !strlen(pcSecondlySeparator)
        ){
            return -1;
    }

	// 拷贝字符串
    strncpy(caBigBuff , pcBuff , strlen(pcBuff));
    strncpy(caInBuff  , pcInBuff, strlen(pcInBuff));
    strncpy(caFirstSeparator , pcFirstSeparator ,strlen(pcFirstSeparator));
    strncpy(caSecondlySeparator , pcSecondlySeparator , strlen(pcSecondlySeparator));

	// 根据第一分隔符进行分割
    pStrtok = strtok( caBigBuff , caFirstSeparator );

    while( pStrtok != NULL )
    {
		// 查找第二分割符
        pStrstr = strstr(pStrtok , caSecondlySeparator );
        if( pStrstr != NULL )
        {
            *pStrstr = '\0';
            printf("%s\n",pStrtok);

			// 查找指定数据
            if( strstr(pStrtok , caInBuff) != NULL )
            {
                strncpy(caOutbuff, pStrstr + strlen(caSecondlySeparator),strlen(pStrstr + strlen(caSecondlySeparator)));
                strncpy(pcRetBuff, caOutbuff , strlen(caOutbuff));
                return  0;
            }
        }
        pStrtok = strtok( NULL , caFirstSeparator);        
    }
    return -1;
}

int main()
{
    char caOutBuff[1024] = {0x00};

    int iRet = BackMapp("1,2,3:1@|4,5,6:2@|7:3@|8:-1@|", "2" , caOutBuff , "@|" , ":");
    if(iRet == 0)
    {
        printf("对应的返回值为[%s]\n" , caOutBuff);
    }
}
