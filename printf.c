#include "main.h"
#include<stdarg.h>

int _printf(const char *format, ...)
{
	/* For any Iterative Operation */
	int i = 0;

	/* how many %* that aren't %% */
	unsigned int identifiers;

	/* Number of Identifiers */
	identifiers = _contains(format, '%');

	/* Primary Buffer Size */
	int BUFF_SIZE = _strlen(format) - (identifiers * 2);

	/* Instantiating Buffer */
	char* buffer[BUFF_SIZE];

	/* Shoving args in list */
	va_list args;
	va_start(args, format);

	/* If string is nonexist, die */
	if (!format)
		return (0);

	/* While string is alive or smth*/
	while(format)
	{
		/* Detecting identifier in code
		 * whilst ensuring next char exists
		 */
		if ((*format == '%') && (*(format + 1) != '\0'))
		{
			/* Handling depending on char after identifier*/
			switch (*(format + 1))
			{
				case 's':
					/* Something _strlen() string arg, realloc
					 * Increment i by strlen or smth
					 */

					/* Trying to get length of passed string */
					int pass_str_len = _strlen(va_arg(args, char*));

					/* Incrememnting buffersize to fit new string*/
					BUFF_SIZE += pass_str_len;

					/* Shoving str values into buffer*/


					/* Realloc? pls review*/
					free(buffer);
					buffer = malloc(BUFF_SIZE * sizeof(char));

					/* Incrementing iterator i by string length
					 * So we'd be able to insert at proper
					 * index in buffer
					 */
					i += pass_str_len;
					break;
				case 'c':
					/* Something add 1B to buffer and realloc
					 * Increment i by 1
					 */
					break;
				case '%':
					/* Something add 1B, shove %, realloc
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
			/* ERROR SCREAMING AT ME PLS HELP */
			*(buffer + i) = (char *)(format + i);
			i++;
		}
	}

	return (identifiers);
}
