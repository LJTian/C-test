#include <stdio.h>

#define 	FOTMAT_TYPE_INT   	"d"
#define 	FOTMAT_TYPE_CHAR 	"s"

void main(void)
{
	printf("main start~\n");

	// * 表示的是格式化长度， " 宏 " 用于格式化变量类型的
	printf("num is : %0*" FOTMAT_TYPE_INT "\n", 4 ,100 );



	printf("main end~\n");

}
