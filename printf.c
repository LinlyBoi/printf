#include "main.h"
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
	int buff_idx, fmt_idx; /* Indexes */
	unsigned int identifiers, BUFF_SIZE, printed;
	char *buffer; /*where non formated things are stored*/
	va_list args;

	va_start(args, format);

	identifiers = _contains(format, '%'); /* instances of %s, %c etc */
	BUFF_SIZE = _strlen(format) - identifiers;
	buffer = (char *) malloc(BUFF_SIZE); /* sized of the non % instances only*/
	if (!buffer)
		return (-1);

	if (!format) /* No string. No laundry */
		return (0);

	buff_idx = fmt_idx = 0; /*chain assignment*/
	printed = 0; /*this alone due to diff type*/
	while (*(format + fmt_idx))
	{
		if ((*(format + fmt_idx) == '%') && (*(format + fmt_idx + 1)))
		{
			if (buffer) /* printing and clearing buffer on formatted things */
			{
				printed += _puts(buffer);
				_memset(buffer, 0);
				buffer = (char *) malloc(BUFF_SIZE);
				if (!buffer)
					return (-1);
				buff_idx = 0;
			}
			printed += fmt(*(format + fmt_idx + 1), args);
				fmt_idx += 2;
		}
		else
		{
			*(buffer + buff_idx) = *(format + fmt_idx); /* filling up buffer */
			buff_idx++;
			fmt_idx++;
		}
	}
	if (buffer)
	{
		_puts(buffer);
		free(buffer);
	}
		return (printed);
}
int fmt(char c, va_list args)
{
	switch (c) /*this needs to shrink*/
	{
		case 's':
			return(_puts(va_arg(args, char*)));
			break;
		case 'c':
			return (_putchar(va_arg(args, int)));
			break;
		case '%': /*add 1 byte*/
			return (_putchar('%'));
			break;
		default:
			return (0);
	}

}
