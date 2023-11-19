/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergioprt <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:45:54 by psergiopr         #+#    #+#             */
/*   Updated: 2023/11/17 18:46:28 by psergiopr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_format(const char *format, int i, va_list args)
{
	if (format[i + 1] == '%')
		return (ft_putchar(format[i + 1]));
	else if (format[i + 1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format[i + 1] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format[i + 1] == 'i' || format[i + 1] == 'd')
		return (ft_print_int(va_arg(args, int)));
	else if (format[i + 1] == 'u')
		return (ft_print_int_u(va_arg(args, unsigned int)));
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
/*
int	main(void)
{
	char			c;
	char			*str;
	int				num; 
	void			*ptr;
	unsigned int	num2;

	c = 'd';
	str = "is Luka";
	//num = -2147483648;
	num = 4;
	num2 = 22300;
	ptr = (void *)0x12345678;
	ft_printf("_my: %% (String) (s) My name %s! | Char (c): %c\n", str, c);
	printf("sys: %% (String) (s) My Name %s! | Char (c): %c\n", str, c);
	ft_printf("_my: Number(d): %d | (i): %i | (u): %u\n", num, num, num2);
	printf("sys: Number(d): %d | (i): %i | (u): %u\n", num, num, num2);
	ft_printf("_my:Pointer(p): %p | Hex(x): %x | Hex(X): %X\n", ptr, num2, num2);
	printf("sys:Pointer(p): %p | Hex(x): %x | Hex(X): %X\n", ptr, num2, num2);
	return (0);
}*/
