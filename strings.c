#include "main.h"

/**
 * _strlen - nuts
 */
int _strlen(char *str)
{
  if (*str)
    return (1 + _strlen(str++));
  else
    return (0);
}
