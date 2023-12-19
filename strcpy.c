#include "main.h"
#include <stdlib.h>

/**
 * _strcpy - strcpy with an n
 * @dest: the buffer we copying to
 * @src: the idot we ctrl+c-ed
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int s_idx, i, strlen;
	char *new_me;

	new_me = malloc(_strlen(dest) + _strlen(src) + 1);
	strlen = _strlen(src);

	s_idx = -1;
	while (*(dest + ++s_idx))
		*(new_me + s_idx) = *(dest + s_idx);

	for (i = 0; i < strlen; i++)
		*(new_me + s_idx++) = *(src + i);
	*(new_me + _strlen(new_me)) = '\0';

	return (new_me);
}
