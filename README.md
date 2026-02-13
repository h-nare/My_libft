*This project has been created as part of the 42 curriculum by narhakob.*

# Libft

## Description

Libft is a custom C library that reimplements essential standard C functions and provides additional utility functions.
The goal of this project is to strengthen understanding of memory management, pointers, strings, and static library creation.

The final output is a static library: `libft.a`.

---

## Instructions

### Compile

make

### Available Rules

make        # Build libft.a
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Rebuild everything

### Use in Another Project

Include the header in your C files:

#include "libft.h"

Compile your project with the library:

cc main.c libft.a

---

## Resources
- Linux manual pages (`man 3 <function>`)
- 42 subject documentation
- The C standard library documentation

### Use of AI

AI was used for conceptual clarification, documentation improvement, and Makefile review.
All implementations were written and tested independently.


