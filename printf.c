#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * _printf - printf but worse
 * @format: format string
 * @...: ???
 * Return: characters written
 **/
int _printf(const char *format, ...)
{
	int buff_idx = 0;
	int fmt_idx = 0;
	unsigned int identifiers = _contains(format, '%');
	unsigned int BUFF_SIZE = _strlen(format) - identifiers;
	char *buffer, *next;
	char c;
	va_list args;

	va_start(args, format);
	buffer = malloc(BUFF_SIZE);

	if (!format) /* No string. No laundry */
		return (0);
	while (*(format + fmt_idx))
	{
		if ((*(format + fmt_idx) == '%') && (*(format + fmt_idx + 1)))
		{
			switch (*(format + 1)) /*this needs to shrink*/
			{
				case 's':
					next = va_arg(args, char*); /*Store string temporarily*/
					buffer = _strcpy(buffer, next);
					BUFF_SIZE = _strlen(buffer);
					buff_idx += _strlen(next);
					break;
				case 'c': /* add 1 byte and i++ */
					c = (char) va_arg(args, int);
					*(buffer + buff_idx) = c;
					BUFF_SIZE += 1;
					buff_idx += 1;
					break;
				case '%': /*add 1 byte*/
					break;
			}
			fmt_idx += 2;
		}
		else
		{
			*(buffer + buff_idx) = *(format + fmt_idx);
			buff_idx++;
			fmt_idx++;
		}
	}
	write(1, buffer, BUFF_SIZE + 1);
	return (_strlen(buffer));
}
