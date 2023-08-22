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
	unsigned int buff_idx, fmt_idx, buff_size, printed;
	char *buffer; /*where non formated things are stored*/
	va_list args;

	va_start(args, format);
	buff_size = _strlen(format) - _contains(format, '%');
	buffer = (char *) malloc(buff_size); /* sized of the non % instances only*/

	if (!format && !buffer) /* No string. No laundry */
		return (0);

	buff_idx = fmt_idx = printed = 0; /*chain assignment*/
	while (*(format + fmt_idx))
	{
		if ((*(format + fmt_idx) == '%') && (*(format + fmt_idx + 1)))
		{
			if (buffer) /* printing and clearing buffer on formatted things */
			{
				printed += _puts(buffer);
				buff_size -= _strlen(buffer);
				_memset(buffer, 0);
				buffer = (char *) malloc(buff_size);
				if (!buffer)
					return (-1);
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
			_putchar('%'); /* TODO make this cleaner */
			_putchar(c);
			return (2);
	}

}
