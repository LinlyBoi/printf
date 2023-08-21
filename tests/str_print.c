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
	char *test_1 = "pls";
/*
 * Brain ded to think bout test cond
 */
	_printf(" suh %s\n%s\n", test_0, test_1);
	return (0);

}
