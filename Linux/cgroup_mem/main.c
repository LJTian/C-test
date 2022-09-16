#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 

#define M_BYTE (1<<20)

int main()
{
	void *Malloc[20];
	int i;
	int num;
	printf( "请输入num:\n");
	scanf( "%d", &num );
	printf( "m = %d\n", num);
 
	for ( i = 0 ; i < num ; i++ )
	{
		Malloc[i] = (char *)malloc( 1024 *  M_BYTE );
		memset( Malloc[i], 'A', 1024 * M_BYTE );
		memset( Malloc[i] + (1024 * M_BYTE) - 1 , '\0', 1 );
		sleep(1);
		printf("%d\n", i);
	}

	while(1)
		sleep(5);

	return 0;
}
