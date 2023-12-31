#include "main.h"
#include <stdlib.h>

/**
 * _strlen - Takes string and return its length
 *
 * @str: Address to the head of the string (Array of Characters) (Lost btw)
 *
 * Return: Length of String
 */
int _strlen(const char *str)
{
	if (*str)
		return (1 + _strlen(++str));
	else
		return (0);
}

/**
 * _contains - gets number of unique identifiers
 *
 * @str: da string
 * @c: basically almost always '%'
 *
 * Return: number of unique cases of "%*" that aren't "%%"
 */
int _contains(const char *str, char c)
{
	if (*str)
	{
		if (*str == c && *(str + 1) != c && *(str - 1) != c)
			return (1 + _contains(str + 1, c));
		else
			return (_contains(str + 1, c));
	}
	else
		return (0);
}

/**
 * append - shoved character at the end
 *
 * @str: main string
 * @c: character getting shoved
 *
 * Return: da string but appended
 */

char *append(char *str, char c)
{
	int len, i;
	char *new_me;

	len = _strlen(str);

	new_me = malloc(len + 1);
	i = -1;
	while (*(str + ++i))
		*(new_me + i) = *(str + i);

	*(new_me + i++) = c;
	*(new_me + len + 1) = '\0';
	return (new_me);
}

/**
 * str_up - changes all lowercase letters of a string
 * to uppercase
 * @s: string to modify
 *
 * Return: the resulting string
 */
char *str_up(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;
	}

	return (s);
}
