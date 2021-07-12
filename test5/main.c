#include <stdio.h>
#include <string.h>
#include "include/vlog.h"
#include "include/printlog.h"

int main(){
	int iRet = logInit("/opt/vlog.log",strlen("/opt/vlog.log"),1);
	printf("%d\n",iRet);

	vLog(LOG_INFO,"%s","tian1.so");
	vLog(LOG_DEBUG,"%s","tian2.so");
	vLog(LOG_ERROR,"%s","tian3");
	printlog();	
	return 0;
}

