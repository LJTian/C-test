#ifndef __VLOG_H
#define __VLOG_H
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>


extern int stiLogLv;

#ifdef  __cplusplus
extern "C" {
#endif

#define LOG_INFO  0
#define LOG_ERROR 1
#define LOG_DEBUG 2

#define vLog( logLv, formate,args...) \
do{ \
        if(logLv == LOG_INFO && logLv <= stiLogLv) \
        { \
            printLog(__FILE__, __LINE__, " INFO" , (formate),##args ); \
        }else if(logLv == LOG_ERROR && logLv <= stiLogLv) \
        { \
            printLog(__FILE__, __LINE__, "ERROR" , (formate),##args ); \
        }else if(logLv == LOG_DEBUG && logLv <= stiLogLv) \
        { \
            printLog(__FILE__, __LINE__, "DEBUG" , (formate),##args); \
        } \
        else{ \
            ; \
        } \
	}while(0)


int logInit(const char *pcLogAllName , int iLogAllNameLen , int iLogLv);

void printLog(const char *pcFileName , int iLineNum , const char *pcLogLv ,const char * formate,...);


#ifdef  __cplusplus
}
#endif

#endif /*__VLOG_H*/

