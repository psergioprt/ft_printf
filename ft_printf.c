/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:32:32 by pauldos-          #+#    #+#             */
/*   Updated: 2023/11/14 16:13:02 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

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
	char	c;
	char	*str;
	int		num;

	c = 'd';
	str = "is Luka";
	num = -2147483648;
	ft_printf("My name %s! Character: %c. Number: %d\n", str, c, num);
	printf("My name %s! Character: %c. Number: %d\n", str, c, num);
	return (0);
}
