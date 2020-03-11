#include "common.h"

void decryption(char *filename)
{
	FILE *fdst; char byte; unsigned short password = 0;

	//Open the dst file and handle the error
	fdst = fopen(filename, "rb");
	if(fdst == NULL)
	{
		perror(filename);
		exit(17);
	}

	//Extraction of password 
	fseek(fdst, +54, SEEK_SET);
	int i;
	unsigned short n = sizeof(short) * 8;
	for (i = 0; i < n; i++ )
	{
		fread(&byte, 1, 1, fdst);
		password <<= 1;
		if (byte & 1)
		{
			password |= 1;
		}
		printf("byte value:%hhx\n", byte);
	}
	printf("password:%hd\n", password);

}

