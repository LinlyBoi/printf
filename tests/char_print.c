#include "../main.h"

/**
 * main - testing printing of only char
 *
 * Return: deadth
 */

int main(void)
{
	char c = 'c';

	_printf("%c%c", c, c);
	_printf("cat: %c\n", c);
	return (0);
}
