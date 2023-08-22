#ifndef MAIN_H_
#define MAIN_H_
#include <stdarg.h>
int _printf(const char *format, ...);
int _contains(const char *str, char c);
int _strlen(const char *str);
char *_strcpy(char *dest, char *src);
char *append(char *str, char c);
int _puts(char *str);
int _putchar(char c);
char *_memset(char *str, int bval);
int fmt(char c, va_list args);

#endif
