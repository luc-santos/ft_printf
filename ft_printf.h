#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int ft_printf(const char *s, ...);
int	check_case(char *s, char c);
int	conversions(char c, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putul(unsigned long nb, char *base);
int	ft_putint(int n);
int	ft_putptr(void *ptr);

#endif