#include "main.h"

/**
 * _memset - sets values of bytes to specific value
 *
 * @adr: head address
 * @n: number of bytes
 *
 * Return: pointer to place
 */

char* _memset(char *str, int bval)
{
	int i;

	for (i = 0; i < _strlen(str); i++)
	{
		*(str + i) = bval;
	}

	return (str);
}
