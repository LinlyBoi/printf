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
	unsigned int buff_idx, fmt_idx, printed;
	char *buffer; /*where non formated things are stored*/
	va_list args;

	if (!format && !buffer) /* No string. No laundry */
		return (0);
	va_start(args, format);

	buffer = (char *) malloc(_strlen(format) - _contains(format,'%')); /* sized of the non % instances only*/
	buff_idx = fmt_idx = printed = 0; /*chain assignment*/
	while (*(format + fmt_idx))
	{
		if ((*(format + fmt_idx) == '%') && (*(format + fmt_idx + 1)))
		{
			if (buffer) /* printing and clearing buffer on formatted things */
			{
				printed += _puts(buffer);
				_memset(buffer, 0);
				buff_idx = 0;
			}
			printed += fmt(*(format + fmt_idx + 1), args);
			fmt_idx += 2;
		}
		else
			*(buffer + buff_idx++) = *(format + fmt_idx++); /* filling up buffer */
	}
	if (buffer)
	{
		_puts(buffer);
		free(buffer);
	}
		return (printed);
}
/**
 * fmt - format because its too chonky for printf
 * @c: format character (for now)
 * @args: the arguments to pop from
 * Return: bytes written to stdout
 */
int fmt(char c, va_list args)
{
	switch (c) /*this needs to shrink*/
	{
		case 's':
			return (_puts(va_arg(args, char*)));
		case 'c':
			return (_putchar(va_arg(args, int)));
		case '%': /*add 1 byte*/
			return (_putchar('%'));
		default:
			return (0);
	}

}
