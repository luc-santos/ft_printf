*This project has been created as part of the 42 curriculum by lucsanto.*

# ft_printf

## Description

**ft_printf** is a custom implementation of the C standard library function `printf`.

The goal of this project is to recode `printf()` and build a static library named `libftprintf.a`.
Through this project, the main concepts practiced are variadic functions, formatted output parsing,
base conversion, pointer representation, and careful control of return values.

The function prototype is:

```c
int ft_printf(const char *format, ...);
```

This implementation does **not** reproduce the original `printf` buffer management, as required by
the project subject. Instead, it focuses on handling the mandatory conversions and returning the
number of characters printed.

The mandatory conversions implemented are:

| Conversion | Description |
|---|---|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a `void *` pointer in hexadecimal format |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed decimal integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints an unsigned number in lowercase hexadecimal |
| `%X` | Prints an unsigned number in uppercase hexadecimal |
| `%%` | Prints a percent sign |

---

## Instructions

### Requirements

This project is written in C and follows the 42 Norm.

The project subject allows the following external functions:

- `malloc`
- `free`
- `write`
- `va_start`
- `va_arg`
- `va_copy`
- `va_end`

In this implementation, output is performed with `write`, according to the project restrictions.

### Compilation

To compile the library, run:

```bash
make
```

This creates the static library at the root of the repository:

```bash
libftprintf.a
```

The Makefile compiles the source files with:

```bash
cc -Wall -Wextra -Werror
```

and archives the object files using:

```bash
ar rcs libftprintf.a
```

### Makefile rules

| Rule | Description |
|---|---|
| `make` or `make all` | Builds `libftprintf.a` |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and `libftprintf.a` |
| `make re` | Rebuilds the library from scratch |

---

## Usage

Include the header in your source file:

```c
#include "ft_printf.h"
```

Compile your program with the generated library:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o program
```

Example:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Project: %s\n", "ft_printf");
    ft_printf("Decimal: %d\n", -42);
    ft_printf("Unsigned: %u\n", 42);
    ft_printf("Hex lower: %x\n", 255);
    ft_printf("Hex upper: %X\n", 255);
    ft_printf("Percent sign: %%\n");
    return (0);
}
```

Possible output:

```text
Project: ft_printf
Decimal: -42
Unsigned: 42
Hex lower: ff
Hex upper: FF
Percent sign: %
```

---

## Project Structure

```text
.
├── Makefile
├── ft_printf.c
├── ft_printf.h
├── ft_printf_handler.c
├── ft_printf_numbers.c
└── ft_printf_utils.c
```

### File overview

| File | Responsibility |
|---|---|
| `ft_printf.c` | Contains the main `ft_printf` function and iterates through the format string |
| `ft_printf_handler.c` | Checks valid conversion specifiers and routes each conversion to the correct function |
| `ft_printf_numbers.c` | Handles signed integers, unsigned numbers, hexadecimal numbers, and pointers |
| `ft_printf_utils.c` | Contains basic output helpers for characters and strings |
| `ft_printf.h` | Contains function prototypes and required includes |
| `Makefile` | Builds the static library |

---

## Algorithm and Data Structure

The main algorithm is based on a linear scan of the format string.

`ft_printf` receives a constant format string and a variable number of arguments.
It initializes a `va_list` with `va_start` and then reads the format string one character at a time.

When the current character is not `%`, the character is printed directly.

When `%` is found, the next character is checked against the supported conversion set:

```text
cspdiuxX%
```

If the specifier is valid, the function retrieves the corresponding argument using `va_arg`
and sends it to the appropriate helper function.

The simplified flow is:

1. Initialize a character counter.
2. Initialize the variadic argument list with `va_start`.
3. Traverse the format string from left to right.
4. Print regular characters directly.
5. When a `%` is found, validate the next character as a supported conversion.
6. Retrieve the correct argument from `va_list`.
7. Print the argument using the matching helper function.
8. Add the number of printed characters to the counter.
9. End the variadic argument handling with `va_end`.
10. Return the total number of printed characters.

### Data structure justification

This project does not require a complex custom data structure.

The central data structure is `va_list`, from `<stdarg.h>`, because the function must accept an
unknown number of arguments, just like the original `printf`.

For number conversion, the implementation uses a temporary character array to store digits in reverse
order before printing them in the correct order. This is useful because repeated division by the base
naturally produces digits from right to left.

For example, when converting an unsigned number to hexadecimal:

1. Divide the number by the base length.
2. Store the remainder as the next digit.
3. Repeat until the number becomes zero.
4. Print the stored digits from the end to the beginning.

This approach avoids unnecessary dynamic allocation for numeric conversions and keeps the implementation
simple, predictable, and compatible with the scope of the mandatory project.

---

## Implementation Notes

- The function returns the number of characters printed.
- `%d` and `%i` are handled as signed decimal integers.
- `%u`, `%x`, and `%X` reuse the same unsigned number conversion logic with different bases.
- `%p` prints the pointer address with the `0x` prefix.
- A null string is printed as `(null)`.
- A null pointer is printed as `(nil)`.
- The implementation is split into small helper functions to keep the code readable and easier to maintain.
- The library is created with `ar`, as required by the subject.

---

## Resources

The following resources were used as references during the development and review of this project:

- 42 ft_printf subject
- `man 3 printf`
- `man 3 stdarg`
- `man 2 write`
- C documentation about variadic functions
- C documentation about number systems and hexadecimal conversion
- Peer discussion and testing during the 42 learning process

### AI usage

For this specific project, AI was not used in the algorithm implementation, and it was not necessary for solving the core logic of the project.

The only use of AI was to help structure this README and improve its presentation, making the documentation clearer for peers, staff, and recruiters.

---

## Author

**lucsanto**  
42 São Paulo student
