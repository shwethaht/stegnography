#include "common.h"

int main(int argc, char *argv[])
{
	error_handlings(argv, argc);
	if (strncmp("-e", argv[1], 2) == 0)
	{
		encryption(argv);
	}
	
	if(strncmp("-d", argv[1], 2) == 0)
	{
		decryption(argv[2]);
	}
	return 0;

}
