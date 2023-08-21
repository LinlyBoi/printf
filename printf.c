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
	int buff_idx;
	unsigned int identifiers, BUFF_SIZE;
	char *buffer, *next;
	va_list args;


	va_start(args, format);
	identifiers = _contains(format, '%');
	BUFF_SIZE  = _strlen(format) - (identifiers * 2);
	buffer = malloc(BUFF_SIZE);

	if (!format) /* No string. No laundry */
		return (0);
	buff_idx = 0;
	while (format)
	{
		if ((*format == '%') && (*(format + 1))) /*hello %s*/
		{
			switch (*(format + 1)) /*this needs to shrink*/
			{
				case 's':
					next = va_arg(args, char*); /*Store string temporarily*/
					buffer = _strcpy(buffer, next);
					BUFF_SIZE += _strlen(buffer);

					break;
				case 'c': /* add 1 byte and i++ */
					break;
				case '%': /*add 1 byte*/
					break;
			}
		}
		else
		{
			*(buffer + buff_idx) = *(format + buff_idx);
			buff_idx++;
		}
	}

	write(1, &buffer, BUFF_SIZE);
	return (_strlen(buffer));
}
