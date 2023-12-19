#include "main.h"

/**
 * _memset - sets values of bytes to specific value
 *
 * @adr: head address
 * @bval: number of bytes
 *
 * Return: pointer to place
 */

char *_memset(char *adr, int bval)
{
	int i;

	for (i = 0; i < _strlen(adr); i++)
	{
		*(adr + i) = bval;
	}

	return (adr);
}
