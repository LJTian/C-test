#include<stdio.h>
#include<stddef.h>

typedef struct {
	char eum1[12];
	char eum2[24];
	int eum3;
	char eum4[36];
}StructTmp;

typedef struct {
	char sStringName[1024];
	long lOffset;
	char sDataType[3];
	long lStringLong;
}StructDesc;

StructDesc temp[] = 
{
	{ "eum1", offsetof( StructTmp, eum1) , "s", 12	},
	{ "eum2", offsetof( StructTmp, eum2) , "s", 24	},
	{ "eum3", offsetof( StructTmp, eum3) , "i", 0 	},
	{ "eum4", offsetof( StructTmp, eum4) , "s", 36	},
	{ "null", 0, "nil", 0}
};

void GetValueByStringName(char *sDataStart,char *sData, char *sStringName)
{
	int i;

	if ( !strlen(sStringName) || !memcmp(sStringName, "null", 3 ))
	{
		return;
	}

	for( i = 0 ; ; i++)
	{
		if ( !strcmp( "null", temp[i].sStringName ))
			break;
		
		if ( !strcmp( sStringName, temp[i].sStringName ))
		{
			printf(" %s : %ld : %s : %ld \n",
			   	temp[i].sStringName, temp[i].lOffset, temp[i].sDataType, temp[i].lStringLong );
			memcpy(sData, sDataStart + temp[i].lOffset, temp[i].lStringLong );
		}
	}	
}

void main()
{
	StructTmp tmp;
	long iOffset = 0;
	int iSizeof = 0;
	int i;
	char tmpBuff[1024];

	memset( tmpBuff, 0x00, sizeof(tmpBuff));
	memset( &tmp, 0x00, sizeof(StructTmp));

	memcpy( tmp.eum1,"eum1",4);
	memcpy( tmp.eum2,"eum2",4);
	memcpy( tmp.eum4,"eum4",4);
	tmp.eum3 = 3;
	
	GetValueByStringName( &tmp, tmpBuff, "eum4");

	printf("%s : %s \n", "eum4", tmpBuff );
}

