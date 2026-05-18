#include "ft_printf.h"


int	ft_putul(unsigned long nb, char *base)
{
	int		i;
	int		counter;
	int		base_len;
	char	c[65];
	
	i = 0;
	counter = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nb == 0)
		return (ft_putchar('0'));
	while (nb > 0)
	{
		c[i++] = base[nb % base_len];
		nb /= base_len;
	}
	while (i > 0)
		counter += write(1, &c[--i], 1);
	return (counter);
}

int	ft_putint(int n)
{
	long	nb;
	int		counter;

	nb = n;
	counter = 0;
	if (nb < 0)
	{
		counter += write(1, "-", 1);
		nb *= -1;
	}
	counter += ft_putul((unsigned long)nb, "0123456789");
	return (counter);
}

int	ft_putptr(void *ptr)
{
	int	counter;

	counter = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	counter += ft_putstr("0x");
	counter += ft_putul((unsigned long)ptr, "0123456789abcdef");
	return (counter);
}