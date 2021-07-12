#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "vlog.h"

int stiLogLv; //默认ERROR级别

// 简单日志封装
//
// tianlj
//
// 先初始化后再进行调用，目前分为3个级别 INFO < ERROR < DEBUG

static char stcaLogAllName[1024]; //日志全路径

// 函数名称: logInit
// 入    参:pcLogAllName:文件全路径名称 iLogAllNameLen:文件名称长度 iLogLv:日志级别
// 出    参:
// 返 回 值: 0:成功 其它失败
//
int logInit(const char *pcLogAllName , int iLogAllNameLen , int iLogLv )
{
	FILE *fp;
	if( 0 == strlen(pcLogAllName) )
	{
		return -2;
	}
	if( NULL == memcpy(stcaLogAllName , pcLogAllName ,iLogAllNameLen ))
	{
		return -3;
	}
    	stiLogLv = iLogLv;
    	printf("%s  %d \n" , pcLogAllName , stiLogLv);
	fp = fopen(pcLogAllName,"a");
	if(fp != NULL )
	{
		flockfile(fp);
		fclose(fp);
		return 0;
	}else
	{
		return -1;
	}
}

// 打印日志
void printLog(const char *pcFileName , int iLineNum , const char *pcLogLv,const char * formate,...)
{
	va_list ap;
	char *msgbuf = NULL;
	FILE * fp = NULL;
	int res;
	va_start(ap, formate);
	res = vasprintf(&msgbuf, formate, ap);
	va_end(ap);
	time_t ttime;
	struct tm *p;
	char timestr[1024]={0};
	ttime = time(NULL);
	
	time( &ttime);
	p = localtime( &ttime );
	if(p == NULL )
	{
		printf("p is NULL\n ");
	}
	printf("p not is NULL\n ");
   	sprintf( timestr, "%02d-%02d %02d:%02d:%02d [%s] %s %d : %s", ( 1+p->tm_mon), p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec, pcLogLv ,pcFileName , iLineNum , msgbuf);
	
    	printf("%s\n",timestr);
	fp = fopen(stcaLogAllName,"a");
	if(fp!=NULL){
		flockfile(fp);
		fprintf(fp,"%s\n",timestr);
		funlockfile(fp);
		fclose(fp);
	}
	free(msgbuf);
	msgbuf = NULL;
	return;
}

/*
//
//使用案例
//
int main()
{
	int i = logInit("/home/tianlj/vlog.log", strlen("/home/tianlj/vlog.log") , 1 );
	printf("%d\n",i);
	vLog(LOG_INFO, "%s","tian0");
	vLog(LOG_DEBUG, "%s","tian2");
	vLog(LOG_ERROR, "%s","tian1");
	return 0;
}
*/
