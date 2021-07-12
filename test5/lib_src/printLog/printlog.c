#include <stdio.h>
#include "../../include/vlog.h"
#include "printlog.h"

int printlog(){
	vLog(LOG_ERROR,"%s","printLog.so");
	return 0;
}
