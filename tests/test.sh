#!/usr/bin/bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 $1 ../*.c -o a
./a
