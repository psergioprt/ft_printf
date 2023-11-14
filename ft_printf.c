/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:32:32 by pauldos-          #+#    #+#             */
/*   Updated: 2023/11/14 11:45:10 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
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
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int	char_len;
	int	i;
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
	char c = 'd';
	ft_printf("My name is Luka!%%c\n", c);
	printf("My name is Luka!%c\n", c);
	return (0);
}
