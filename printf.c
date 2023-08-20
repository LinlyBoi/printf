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
	int i, j;
	unsigned int identifiers, BUFF_SIZE;
	char *buffer, *next;
	va_list args;


	va_start(args, format);

	identifiers = _contains(format, '%');
	BUFF_SIZE  = _strlen(format) - (identifiers * 2);

	if (!format) /* No string. No laundry */
		return (0);


	i = 0; /*TODO:gotta rename those*/
	j = 0;
	buffer = "";
	while (format)
	{
		if ((*format == '%') && (*(format + 1)))
		{
			switch (*(format + 1))
			{
				case 's':
					next = va_arg(args, char*); /*Store string temporarily*/
					_strcpy(&buffer[j], next);
					j += _strlen(next);
					BUFF_SIZE += _strlen(next);

					break;
				case 'c':
					/*
					 * You don't add 1Byte because %c becomes a single char so less to reallocate
					 * Increment i by 1
					 */
					break;
				case '%':
					/*
					 * Something add 1B, shove %, realloc
					 * increment i by 1
					 */
					break;
			}
			/*
			 * something something increment i
			 * by size of argument value
			 * also no forgor about realloc
			 */
		}
		else
		{
			*(buffer + i) = *(format + i);
			i++;
		}
	}

	write(1, buffer, BUFF_SIZE);
	return (_strlen(buffer));
}
