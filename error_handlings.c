#include "common.h"

void error_handlings(char **argv, int args)
{
	if (*(argv[1]+1) != 'e' && *(argv[1]+1) != 'd')
	{
		printf("Please enter the right option\n");
		exit(13);
	}

	size_t len; 
	char *cptr;

	// Check the options 
	if (strncmp(argv[1], "-e", 2) == 0)
	{

		//Check the No. of args in -e
		if (args != 4 && args != 5)
		{
			printf("Incorrect No. of args\n");
			printf("Usages:\n<./steganography> <options(-e)> <scr.bmp> <sct.txt> <dst.bmp(optional)>\n");
			exit(1);
		}

		// Check the extension (.bmp)
		len = strlen (argv[2]);
		cptr = argv[2] + (len - 3);
		if (strncmp(cptr, "bmp", 3) != 0)
		{
			printf("hello\n");
			printf("Please provide a *.bmp file format for scr\n");
			exit(2);
		}

		//Check *.bmp file code
		else
		{
			unsigned char byte;
			FILE *fsrc = fopen(argv[2], "rb");
			fread(&byte, 1, 1, fsrc);
			if (byte != 0x42)
			{
				printf("Incorrect file format of src and please provide *.bmp file for src");
				exit(3);
			}
			else
			{
				fread(&byte, 1, 1, fsrc);

				if (byte != 0x4D)
				{
					printf("Incorrect file format of src and please provide *.bmp file for src");
					exit(4);
				}

			}



			//Check the extention (.txt)
			len = strlen (argv[3]);
			cptr = argv[3] + (len - 3);
			if (strncmp(cptr, "txt", 3) != 0)
			{
				printf("Please provide a *.txt file format for sct\n");
				exit(5);
			}

			//Check the extention dst file format (*.mbp)
			if (argv[4] != NULL)
			{
				len = strlen (argv[4]);
				cptr = argv[4] + (len - 3);
				if (strncmp(cptr, "bmp", 3) != 0)
				{
					printf("Please provide a *.bmp file format for dst\n");
					exit(6);
				}

			}
		}
	}
	// Check the option
	else if (strncmp(argv[1], "-d", 2) == 0)
	{

		//Check the No. of args in -d
		if (args != 3 &&  args != 4)
		{
			printf("Incorrect No. of args\n");
			printf("Usages:\n<./steganography> <options(-d)> <dst.bmp> <msg.txt(optional)>\n");
			exit(7);
		}


		// Check the extension (.bmp)
		len = strlen (argv[2]);
		cptr = argv[2] + (len - 3);
		if (strncmp(cptr, "bmp", 3) != 0)
		{
			printf("Please provide a *.bmp file format for dst\n");
			exit(10);
		}

		//Check *.bmp file code
		else
		{
			char byte;
			FILE *fdst = fopen (argv[2], "rb");
			fread(&byte, 1, 1, fdst);
			if (byte != 0x42)
			{
				printf("Incorrect file format of dst and please provide *.bmp file for dst\n");
				exit(11);
			}
			else
			{
				fread(&byte, 1, 1, fdst);

				if (byte != 0x4D)
				{
					printf("Incorrect file format of dst and please provide *.bmp file for dst\n");
					exit(12);
				}

			}
		}
	}

fcloseall();
}
