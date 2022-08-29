#include <stdio.h>

#if 0
#define EXT_MEM_K (*(unsigned short *)0x90002)     // 0x90002 地址内存放地址的值 类似于 #define EXT_MEM_K **p 扩展内存值
#else 
// 默认其值为7M; // 这个是假使值
#define EXT_MEM_K ((1<<13) - (1<<10))
#endif

#define DRIVE_INFO (*(struct drive_info *)0x90080)
#define ORIG_ROOT_DEV (*(unsigned short *)0x901FC)

#if 0
#define LOG_P(a,b) ( printf( "%s\t =\t[0x%08X] [%dM]\n", (a), (b), ( (b)/(1<<20) ) ) ) // 日志打印宏，前面是打印变量名字，后面是变量，16进制打印
#endif 
void LOG_P(char *name, long value)
{
	printf( "%s \t = \t [0x%08X] = [%dM]\n", name, (int)value, (int)(value/(1<<20)));

	return;
}

#

long memory_end = 0;    // 内存最大值
long buffer_memory_end = 0;
long main_memory_start = 0;

int main(void) {

	LOG_P("1<<20", 1<<20); // 1024 * 1024 = 1K * 1024 = 1M
    
	memory_end = (1<<20) + (EXT_MEM_K<<10);

	LOG_P("memory_end", memory_end);	
    //memory_end &= 0xfffff000;

	LOG_P("memory_end", memory_end);
    
#if 1
	if (memory_end > 16*1024*1024)
        memory_end = 16*1024*1024;
    if (memory_end > 12*1024*1024) 
        buffer_memory_end = 4*1024*1024;
    else if (memory_end > 6*1024*1024)
        buffer_memory_end = 2*1024*1024;
    else
        buffer_memory_end = 1*1024*1024;
    main_memory_start = buffer_memory_end;

	LOG_P("memory_end", memory_end);
	LOG_P("buffer_memory_end", buffer_memory_end );
	LOG_P("main_memory_start", main_memory_start );
#endif
	return 0; 
}
