#include "../main.h"
#include <stdio.h>

/**
 *main - ensure append work
 */
int main(void)
{
	char *str, c;

	str = "hello";
	c = 'c';
	str = append(str, c);
	_printf("%s\n", str);
	return (0);

}
