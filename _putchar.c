#include "main.h"

/**
 * _putchar - print character
 * @c: character
 *
 * Return: 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
