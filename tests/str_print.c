#include "../main.h"
#include <string.h>

/**
 * main - Tests if '%s' works within our printf.
 *
 * Return: 0 On Failure, 1 Otherwise Success
 */

int main(void)
{
	char *test_0 = "Hej";
/*
 * Brain ded to think bout test cond
 */
	_printf("%s \n", test_0);
	return (_printf("hey, %s", test_0));

}
