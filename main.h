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
char *_memset(char *adr, int bval);
int fmt(char c, va_list args);
char *_str_reverse(char *str);
char *_itoa(int n, int base);
char *_uitoa(unsigned int n, int base);
char *str_up(char *s);

#endif
