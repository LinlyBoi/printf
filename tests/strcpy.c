#include "../main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * main - why does this not work! I know!
 * Return: 0...unless?
 */
int main(void)
{
	char *str, *str2;

	str = "hello";
	str2 = " world!\n";
	str = _strcpy(str, str2);
	printf("%s", str);
	return (0);
}
