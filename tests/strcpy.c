#include "../main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/**
 * main - why does this not work! I know!
 * Return: 0...unless?
 */
int main(void)
{
	char *str, *str2, c;

	str = "hello";
	str2 = " world!\n";
	str = _strcpy(str, str2);
	c = 'c';

	printf("%s", str);
	write(1, &c, 1);
	return (0);
}
