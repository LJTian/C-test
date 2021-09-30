#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <math.h>

#define NUM_EFFT_FLAG 1


/* 此函数内的 gettimeofday 是属于linux 的 API 其它系统请替换对应的功能函数 */
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

    // printf("iMin is [%d]\t iMax is [%d]\n", iMin, iMax);

    diff = iMax - iMin;
    
    // 入参校验
    if ( 0 > iMaxForNum || 0 > diff )
        return -1;

    // 设置随机数的种子(目前取得是linux 微秒值)
    srand(GetLocaTime());

    // 固定次数获取,防止出现BUG导致函数死循环
    while( iMaxForNum-- )
    {
        num  = rand()%(iMax);
        printf("num is [%d]\n", num);
        if( num >= iMin)
            return num;

        // 提高命中率( 公式是临时想出来的, 不一定没有遗漏 )
        if ( 0 != diff )
        {
            num += num*((iMin - num)/diff+1);
            if ( num < iMax && num >= iMin )
                return num;
        }
    }
    
    // 正常运行情况下,不会走到这一步, 出现异常情况, 此部分可以让函数正确的结束
    return -1;
}

/*
函数名称：bGetRandCode
功     能：生成随机字符串
入     参：
          iType: 0-数字 1-字母 2-字母(大) 3-字母(小) 4-字母 + 数字 5-字母(大) + 数字 6-字母(小) + 数字 其它：-2
          iLen : 生成的字符长度
出     参：pcRandCode : 生成随机字符串的地址
返 回 值：0 : 成功  -1 : 失败 -2: iType 类型错误 -3 : iLen 值不正确
*/
int bGetRandCode(int iType, char *pcRandCode, int iLen )
{
    // 元素表
    char CodeArrt[62] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    // 三种类型元素的最大值坐标
    int iRandMaxNum[3] = { 10, 36, 62 };

    int iMaxBit = 0 , iMinBit = 0;
    int iMaxLen;
    int iBit = 0 ;
    int iIsOk = 1;

    // 参数校验
    if ( 0 > iLen )
        return -3;

    // 判断生成的数据类型
    switch (iType)
    {
        // 数字
        case 0:

#if NUM_EFFT_FLAG
		if( iLen < 10 )
		{
			iMaxBit = 1;
			iMaxLen = iLen;
			while( iMaxLen-- ) iMaxBit *= 10;
            		sprintf( pcRandCode, "%0*d", iLen, bRandNum( iMinBit, iMaxBit, 10 ));
			return 0;
		}
#endif
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

        // 其它失败
        default:
            return -2;
    }

    iMaxLen = iLen;

    // 长度保护
    pcRandCode[iMaxLen] = '\0';

    // 倒序填写内容
    while( --iMaxLen >= 0 )
    {
        // 生成随机数
        iBit = bRandNum( iMinBit, iMaxBit, 10 );
        if ( iBit < -1 )
             iBit = iMinBit;

        // 类型5需要做特殊处理
        if ( 5 == iType && iBit < iRandMaxNum[1] && iBit >= iRandMaxNum[0] )
            iBit += 26;

        // 写入字符
        pcRandCode[iMaxLen] = CodeArrt[iBit];
    }
    
    /* 检查(默认情况下,如果生成随机数函数调用失败,就是用最小值对应的字符,
    此检查可以控制是否需要对全小值的字符串进行报错处理) */
    if ( iIsOk )
    {
        iIsOk = 0;
        while( --iLen > 0 )
        {
            if( pcRandCode[iLen] != CodeArrt[iMinBit] )
                iIsOk = 1;
        }
    }

    return iIsOk == 0 ? (-1) : (0);
}

#if 0
void TestGenRandCode()
#else 
void main()
#endif
{
    char buff[1024];
    int iRet = 0;
    memset( buff, 0x00, sizeof(buff));
    iRet = bGetRandCode( 0, buff, 16);
    if ( iRet )
    {
        printf( "err! iRet is [%d]", iRet);
    }

    printf("buff is [%s]\n", buff);

}

