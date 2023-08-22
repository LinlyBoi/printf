#include "main.h"
#include <stdlib.h>
/**
 * _str_reverse - reverse a string because I said so
 * @str: da string
 * Return: number in string form
 */
char *_str_reverse(char *str)
{
	unsigned int i, len;
	char *buffer;

	len = _strlen(str);
	buffer = malloc(len);
	if (!buffer)
		return (NULL);
	for (i = 0; i < len; i++)
		*(buffer + len - 1 - i) = *(str + i);
	return (buffer);


}
/**
 * _itoa - turn NUMBA into a STRING
 * @n: NUMBA
 * @base: base
 * Return: numba in string form
 */
char *_itoa(int n, int base)
{
	int i, isNegative, rem;
	char *str;

	str = malloc(1024);
	i = isNegative = 0;
	if (n == 0)
	{
		*(str + i++) = '0';
		*(str + i) = '\0';
		return (str);
	}

	if (n < 0 && base == 10)
	{
		isNegative = 1;
		n = -n;
	}

	while (n != 0)
	{
		rem = n % base;
		*(str + i++) = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		n = n / base;
	}

	if (isNegative)
		*(str + i++) = '-';

	*(str + i) = '\0';

	str = _str_reverse(str);

	return (str);
}

/**
 * _uitoa - turn NUMBA into a STRING
 * @n: NUMBA
 * @base: base
 * Return: numba in string form
 */
char *_uitoa(unsigned int n, int base)
{
	int i, rem;
	char *str;

	str = malloc(1024);
	i = 0;
	if (n == 0)
	{
		*(str + i++) = '0';
		*(str + i) = '\0';
		return (str);
	}


	while (n != 0)
	{
		rem = n % base;
		*(str + i++) = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		n = n / base;
	}


	*(str + i) = '\0';

	str = _str_reverse(str);

	return (str);
}
