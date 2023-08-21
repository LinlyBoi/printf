#include "../main.h"

/**
 * main - test strlen
 * Return: 0 if yes, 1 if no
 */
int main(void)
{
	char *str;
	int len;

	str = "hello";
	len =_strlen(str);
	if (len == 5)
		return (0);
	else
		return (1);

}
