#include "main.h"
#include<stdarg.h>

int _printf(const char *format, ...)
{
	int i = 0;
	int BUFF_SIZE = _strlen(format);
	unsigned int identifiers; /* how many %* that aren't %% */
	va_list args;

	BUFF_SIZE = _strlen(format);

	char* buffer[BUFF_SIZE];

	/* Number of Identifiers */
	identifiers = _contains(format, '%');

	va_start(args, format);

	if (!format)
		return (0);

	while(format)
	{
		if (*format == '%')
		{
			switch (*(format + 1))
			{
				case 's':
					break;
				case 'c':
					break;
				case '%':
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
			/* ERROR SCREAMING AT ME PLS HELP */
			*(buffer + i) = (format + i);
			i++;
		}
	}

	return (identifiers);
}
