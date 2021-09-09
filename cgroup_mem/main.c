#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M_BYTE 1024*1024

void main()
{
	void *Malloc[10];
	int i;
 
	for ( i = 0 ; i< 9 ; i++ )
	{
		Malloc[i] = (char *)malloc( 100 *  M_BYTE );
		memset( Malloc[i], 'A', 100 * M_BYTE );
		//sleep(1000);
	}

	while(1)
		sleep(5000);

	for ( i = 0 ; i < 10; i++ )
		free(Malloc[i]);

}
