/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:32:32 by pauldos-          #+#    #+#             */
/*   Updated: 2023/11/16 09:39:44 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write (1, str, len);
	return (len);
}

int	ft_putnbr(int nb, int i)
{
	int long	num;

	num = nb;
	if (nb == -2147483648)
	{
		i = ft_putstr("-2147483648");
		return (i);
	}
	if (nb < 0)
	{
		i = ft_putchar('-');
		nb = -nb;
	}
	if (nb < 10)
	{
		i = ft_putchar(nb + '0');
	}
	else
	{
		i = ft_putnbr(nb / 10, i);
		i = ft_putnbr(nb % 10, i);
	}
	return (i);
}

int	ft_putnbr_u(unsigned int nb, int i)
{
	int long	num;

	num = nb;
	if (nb < 10)
		i = ft_putchar(nb + '0');
	else
	{
		i = ft_putnbr_u(nb / 10, i);
		i = ft_putnbr_u(nb % 10, i);
	}
	return (i);
}

void	ft_putnbr_hex_digit(int hex_digit, int uppercase)
{
	char		hex_chars[16];
	int			i;
	const char	*hex_literal;

	hex_literal = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		hex_chars[i] = hex_literal[i];
		i++;
	}
	if (uppercase)
	{
		hex_chars[10] = 'A';
		hex_chars[11] = 'B';
		hex_chars[12] = 'C';
		hex_chars[13] = 'D';
		hex_chars[14] = 'E';
		hex_chars[15] = 'F';
	}
	write (1, &hex_chars[hex_digit], 1);
}

int	ft_putnbr_hex(unsigned long long nb, int i, int uppercase)
{
	int	j;
	int	hex_digit;
	int	skip_zeros;

	j = 28;
	skip_zeros = 1;
	if (nb == 0)
	{
		i += ft_putchar('0');
	}
	while (j >= 0)
	{
		hex_digit = (nb >> j) & 0xF;
		if (hex_digit != 0 || !skip_zeros)
		{
			skip_zeros = 0;
			ft_putnbr_hex_digit(hex_digit, uppercase);
		}
		j -= 4;
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)&(*str));
		str++;
	}
	return (0);
}

int	ft_putptr(void *ptr, int i)
{
	unsigned long long	addr;

	addr = (unsigned long long) ptr;
	i += ft_putstr("0x");
	i += ft_putnbr_hex(addr, i, 1);
	return (i);
}

int	ft_printf_format(const char *format, int i, va_list args)
{
	if (format[i + 1] == '%')
		return (ft_putchar(format[i + 1]));
	else if (format[i + 1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format[i + 1] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format[i + 1] == 'i' || format[i + 1] == 'd')
		return (ft_putnbr(va_arg(args, int), i));
	else if (format[i + 1] == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int), i));
	else if (format[i + 1] == 'p')
		return (ft_putptr(va_arg(args, void *), i));
	else if (format[i + 1] == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned long long), i, 0));
	else if (format[i + 1] == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned long long), i, 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		char_len;
	int		i;
	va_list	args;

	i = 0;
	char_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (ft_strchr("cspdiuxX%", format[i + 1]))
			{
				char_len += ft_printf_format(format, i, args);
				i++;
			}
		}
		else
			char_len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (char_len);
}

int	main(void)
{
	char			c;
	char			*str;
	int				num; 
	void			*ptr;
	unsigned int	num2;

	c = 'd';
	str = "is Luka";
	num = -2147483648;
	num2 = 22300;
	ptr = (void *)0x12345678;
	ft_printf("_my: %% (String) (s) My name %s! | Char (c): %c\n", str, c);
	printf("sys: %% (String) (s) My Name %s! | Char (c): %c\n", str, c);
	ft_printf("_my: Number(d): %d | (i): %i | (u): %u\n", num, num, num2);
	printf("sys: Number(d): %d | (i): %i | (u): %u\n", num, num, num2);
	ft_printf("_my:Pointer(p): %p | Hex(x): %x | Hex(X): %X\n", ptr, num2, num2);
	printf("sys:Pointer(p): %p | Hex(x): %x | Hex(X): %X\n", ptr, num2, num2);
	return (0);
}
