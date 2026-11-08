# ft_printf

A reimplementation of the C standard library `printf` function, built as a static library (`libftprintf.a`).
Part of the 42 Porto curriculum.

## Supported conversions

| Conversion | Description                              |
|------------|------------------------------------------|
| `%c`       | Single character                         |
| `%s`       | String (prints `(null)` for `NULL`)      |
| `%p`       | Pointer in hexadecimal (prints `(nil)` for `NULL`) |
| `%d`, `%i` | Signed decimal integer                   |
| `%u`       | Unsigned decimal integer                 |
| `%x`       | Hexadecimal, lowercase                   |
| `%X`       | Hexadecimal, uppercase                   |
| `%%`       | Literal `%`                              |

Flags, width and precision are not implemented.

## Project structure

```
project/
├── Makefile
├── ft_printf.h       # prototypes
├── ft_printf.c       # format parsing and main loop
├── utils_print.c     # character, string and decimal output
└── utils_convert.c   # unsigned decimal, hexadecimal and pointer output
```

## Build

The Makefile is inside `project/`:

```bash
cd project
make          # builds libftprintf.a
make clean    # removes object files
make fclean   # removes object files and libftprintf.a
make re       # fclean + all
```

## Use

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s, you are %d years old (%x)\n", "Venâncio", 27, 255);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o program
```

`ft_printf` returns the number of characters written, as the standard `printf` does.

## Known issues

- **Format string ending with `%`:** `ft_printf("abc%")` reads past the end of the string. Detected with AddressSanitizer as a `global-buffer-overflow` in `ft_printf.c`. This must be fixed before relying on the function with arbitrary input.
- **`%u` reads an `int`:** `check_type` calls `va_arg(args, int)` for `%u`. The type should be `unsigned int`. It works for the values tested, but the type is wrong.
- **`va_list` passed by value:** `check_type` receives the `va_list` by value, while `ft_printf` keeps using it afterwards. This works on x86-64 Linux but is not portable. It should be passed as `va_list *`.
- **Unknown conversions:** an unsupported conversion such as `%y` prints nothing, while the standard `printf` prints the sequence literally. The result differs from the libc.

## Status

Mandatory conversions are implemented and match the standard `printf` output for the cases tested. The known issues above are not fixed yet.
