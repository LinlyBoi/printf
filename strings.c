#include "main.h"

/**
 * _strlen - Takes string and return its length
 *
 * @str: Address to the head of the string (Array of Characters) (Lost btw)
 *
 * Returns: Length of String
 */
int _strlen(char *str)
{
  if (str)
    return (1 + _strlen(str++));
  else
    return (0);
}

/**
 * _contains - gets number of unique identifiers
 *
 * @str: da string
 * @c: basically almost always '%'
 *
 * Return: number of unique cases of "%*" that aren't "%%"
 */
int _contains(const char *str, char c)
{
  if (*str)
  {
   if (*str == c && *(str + 1) != c && *(str - 1) != c)
     return (1 + _contains(str + 1, c));
   else
     return (_contains(str + 1, c));
  }
  else
    return (0);
}
