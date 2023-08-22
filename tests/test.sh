#!/usr/bin/bash
gcc -Wno-format -Wall -pedantic -Werror -Wextra -std=gnu89 $1 ../*.c -o a
./a
