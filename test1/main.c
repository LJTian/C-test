#include <stdio.h>

__attribute((constructor))void before()
{
	printf("before main\n");
}

void main(){
	
	printf("main fun");
}
