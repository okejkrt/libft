*This project has been created as part of the 42 curriculum by onkejkrt.*

# Libft - Your very first own library

## Description
This project involves coding a C library that replicates numerous general-purpose functions from the standard C library (`libc`), along with additional custom utility functions designed for string and memory manipulation. The goal of this project is to deeply understand the mechanics of memory management, pointer arithmetic, data structures, and the inner workings of fundamental system functions by implementing them completely from scratch without external dependencies. The resulting library serves as a reusable tool for all future C programming assignments within the 42 curriculum.

## Instructions

### Compilation
The library is compiled using the provided `Makefile`. Every `.c` file is compiled with the strict `-Wall -Wextra -Werror` compiler flags.

To compile the mandatory part (including the standard libc and additional functions), run the following command in the root of the repository:
```bash
make
```

To compile the complete library including the linked list manipulation functions, use the bonus rule:
```bash
make bonus
```

### Cleaning Up
To remove all generated object (`.o`) files from the repository:
```bash
make clean
```

To completely wipe all object files as well as the compiled `libft.a` static library:
```bash
make fclean
```

To perform a clean re-compilation of the entire project:
```bash
make re
```

### Usage
To use this library in your own C projects, include the header file in your code:
```c
#include "libft.h"
```
When compiling your project, link it against the compiled static library:
```bash
gcc main.c -L. -lft -o my_program
```

## Resources
* **The C Programming Language (2nd Edition)** - Brian W. Kernighan and Dennis M. Ritchie.
* **Linux man pages** - Used as the primary technical specification for standard functions behavior (e.g., `man memcpy`, `man strlcat`).

### AI Usage Declaration
In accordance with the 42 AI Instructions guidelines, artificial intelligence was utilized as a peer-learning tool and simulated reviewer during this project. 
* **Tasks Assisted:** AI was used for automated code review, optimizing time complexities (such as implementing branchless logic in character classification functions and a highly optimized one-pass pointer arithmetic loop in `ft_split`), and verifying edge-case memory safety (specifically handling integer overflow protections in `ft_calloc` and ensuring zero memory leaks during `malloc` allocation failures in `ft_lstmap`).
* **Parts Influenced:** AI-assisted code reviews influenced the architectural separation of helper functions utilizing the `static` keyword, helping to adhere closely to the Norm rule limitations while improving nízkoúrovňová memory safety across Part 1, Part 2, and Part 3. No code was copied blindly; all logic was thoroughly reasoned through and peer-reviewed against strict requirements.

## Library Functions Overview

### Part 1 - Libc Functions
* **Character Classification:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`.
* **String Manipulations:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`.
* **Memory Manipulations:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`.
* **Type Conversions & Allocations:** `ft_toupper`, `ft_tolower`, `ft_atoi`, `ft_calloc`, `ft_strdup`.

### Part 2 - Additional Functions
* **Advanced Strings:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`.
* **File Descriptor Outputs:** `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`.

### Part 3 - Linked List Functions
* **Structure Management:** `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`.
* **Memory Deletion & Iteration:** `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`.
