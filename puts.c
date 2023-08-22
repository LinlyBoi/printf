#include "main.h"
#include <unistd.h>

/**
 * _puts - splurges whatever is in buffer
 *
 * @str: pointers to "buffer" or string head
 *
 * Return: Naught
 */

void _puts(char *str)
{
	write(1, str, _strlen(str));
}
