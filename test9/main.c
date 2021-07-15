#include<stdio.h>
#include<string.h>

// 用Vs开启debug 模式才会报Core,非debug模式下可以正常运行
int ReturnCore()
{
	char buff[] = "1234";
	char buff1[8];
	char buff2[] = "1234";

	printf("func ReturnCore start\n");

	memcpy(buff, "12345678", 9);

	printf("func ReturnCore end\n");

	return 0;
}//会在执行这行之后报错,可以准确提示那个变量附近堆栈产生损坏


void main()
{
	printf("func Main start\n");

	ReturnCore();

	printf("func Main start\n");
}
