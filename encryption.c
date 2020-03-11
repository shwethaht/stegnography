#include "common.h"

void encryption(char **argv)
{
	//To encrypt the password 
	unsigned short password = rand() % 10000;
	printf("password is:%hd\n", password);

	//To open src.bmp and dst.bmp
	FILE *fsrc, *fdst;

	fsrc = fopen(argv[2], "rb");
	if (fsrc == NULL)
	{
		perror(argv[2]);
		exit(14);
	}

	if (argv[4] == NULL)
	{
		fdst = fopen("dst.bmp", "wb");
	}
	else
	{
		fdst = fopen(argv[4], "wb");
	}
	if (fdst == NULL)
	{
		perror("fdst");
		exit(15);
	}

	//To copy first 54 bytes from src to dst
	char buffer[54];
	if(( fread(buffer, 54, 1, fsrc)) > 0)
	{
		fwrite(buffer, 54, 1, fdst);
	}

	//To open sct.txt file 
	FILE *fsct = fopen(argv[3], "r");
	if (fsct == NULL)
	{
		perror(argv[4]);
		exit(16);
	}

	//To encrypt the password 
	unsigned short n = sizeof(short)*8;
	char byte;
	unsigned short mask = 0X8000;  
	while(n)
	{
		fread(&byte, 1, 1, fsrc);
		if (password & mask)
			//if ((password >> (n-1)) & 1)
		{
			byte |= 1;
		}
		else 
		{
			byte &= 0XFE;

		}
		//printf("%hhx\n", byte);
		fwrite(&byte, 1, 1, fdst);
		n--;
		mask >>= 1;
	}

	//To find the length of sct file 
	unsigned short count = 0;
	char ch;
	while((ch = fgetc(fsct)) != EOF)
	{
		count += 1;
	}
	//printf("count:%hd\n", count);

	//To encrypt the length
	n = sizeof(short)*8;
	mask = 0X8000;

	while(n)
	{
		fread(&byte, 1, 1, fsrc);
		if (count & mask)
			//if ((password >> (n-1)) & 1)
		{
			byte |= 1;
		}
		else 
		{
			byte &= 0XFE;

		}
		//printf("%hhx\n", byte);
		fwrite(&byte, 1, 1, fdst);
		n--;
		mask >>= 1;
	}
	//Bring fsct file PTR to thr starting of the file 
	rewind(fsct);

	//Encrypt the msg into dst
	while ((ch = fgetc(fsct)) != EOF)
	{
		n = 8;
		unsigned char mask1 = 0X80;
		while(n)
		{
			fread(&byte, 1, 1, fsrc);
			if (ch & mask1)
				//if ((password >> (n-1)) & 1)
			{
				byte |= 1;
			}
			else 
			{
				byte &= 0XFE;

			}
			//printf("%hhx\n", byte);
			fwrite(&byte, 1, 1, fdst);
			n--;
			mask >>= 1;
		}
	}
	// Copy the remaining bytes from src to dst 
	while(fread(&byte, 1, 1, fsrc) > 0)
	{
		fwrite(&byte, 1, 1, fdst);
	}
	fcloseall();
}
