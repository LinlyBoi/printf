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
  if (*str)
    return (1 + _strlen(str++));
  else
    return (0);
}
