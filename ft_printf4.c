/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:46:56 by pauldos-          #+#    #+#             */
/*   Updated: 2023/11/14 09:19:28 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //for malloc, free
#include <unistd.h> //for write
#include <stdarg.h> //for for va_start, va_arg, va_copy
#include <stdio.h> //for real printf

int	ft_printf_write(int c, int i)
{
	i++;
	write (1, &c, 1);
	return (0);
}

int	ft_found_d(int d, int i)
{
	if (d == -2147483648)
	{
		write (1, "-2147483648", 11);
		i = i + 11;

	}	
	else if (d < 0)
	{
		i = ft_printf_write('-', i);
		i = ft_found_d(-d, i);
	}
	else if (d >= 0 && d < 10)
		i = ft_printf_write(d + '0', i);
	else
	{
		i = ft_found_d(d / 10, i);
		i = ft_printf_write(d % 10 + '0', i);
	}
	return (i);
}

int	ft_found_s(char *s, int i)
{
	if (!s)
		i = ft_found_s("(null)", i);
	else
	{
		while (*s)
		{
			write (1, &(*s), 1);
			i++;
			s++;
		}
	}
	return (i);
}

int	ft_next_percent(const char *format, va_list args, int i, int j)
{
	if (format[j] == 's')
		ft_found_s(va_arg(args, char *), i);
		//write (1, "s", 1);
	if (format[j] == 'd')
		ft_found_d(va_arg(args, int), i);
		//write (1, "d", 1);
	if (format[j] == 'x')
		write (1, "x", 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	j;

	i = 0;
	j = 0;
	va_start(args, format);
	while (format[j])
	{
		if (format[j] == '%')
			i = ft_next_percent(format, args, i, ++j);
		else
		{
			i++;
			write (1, &format[j], 1);
		}
		j++;
	}
	va_end(args);
	return (i);
}

int main(void)
{
	//int	i;

	//i = printf("hi\n");
	//printf("i: %i\n", i);
	//
	//ft_printf("MIN number: %i", INT32_MIN);
	//printf("MIN number: %i", INT32_MIN);
	
	ft_printf("me  --> hello 42!\ns: %s, d: %ld, x: %x\n", NULL, -2147483648 ,42);
	printf("real --> hello 42!\ns: %p d: %ld, x: %x\n", NULL, -2147483648 ,42);

	//printf("%s\n", "toto");
	//printf("Magic %s is %d\n", "number", 42);
	//printf("Hexadecimal for %d is %x\n", 42, 42);
	return (0);
}
