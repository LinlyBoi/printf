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
	int buff_idx, fmt_idx;
	unsigned int identifiers, BUFF_SIZE, printed;
	char *buffer;
	va_list args;

	va_start(args, format);

	identifiers = _contains(format, '%');
	BUFF_SIZE = _strlen(format) - identifiers;
	buffer = malloc(BUFF_SIZE);

	if (!format) /* No string. No laundry */
		return (0);

	buff_idx = 0;
	fmt_idx = 0;
	printed = 0;
	while (*(format + fmt_idx))
	{
		if ((*(format + fmt_idx) == '%') && (*(format + fmt_idx + 1)))
		{
			if (*buffer)
			{
				_puts(buffer);
				BUFF_SIZE -= _strlen(buffer);
				free(buffer);
				buffer =  malloc(BUFF_SIZE);
				buff_idx = 0;
			}
			switch (*(format + fmt_idx + 1)) /*this needs to shrink*/
			{
				case 's':
					_puts(va_arg(args, char*));
					break;
				case 'c':
					_putchar(va_arg(args, int));
					break;
				case '%': /*add 1 byte*/
					break;
			}
			/*if (*(format + fmt_idx + 2))*/
				fmt_idx += 2;
			/*else*/
				/*fmt_idx += 1;*/
		}
		else
		{
			*(buffer + buff_idx) = *(format + fmt_idx);
			buff_idx++;
			fmt_idx++;
		}
	}
	if (*buffer)
	{
		_puts(buffer);
		free(buffer);
	}
	return (printed);
}
