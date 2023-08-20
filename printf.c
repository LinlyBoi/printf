#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...)
{
	unsigned int thingies; /*how many %* that aren't %*/
	char *buffer;
	int i;
	va_list stuff;

	thingies = _contains(format, '%');
	va_start(stuff, format);

	if (!format)
		return (0);
	while(format)
	{
		if (*format)
	}



}
