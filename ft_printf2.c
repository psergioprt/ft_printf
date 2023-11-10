/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:22:03 by pauldos-          #+#    #+#             */
/*   Updated: 2023/11/10 12:18:42 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_printf(const char *format, ...)
{
	int	char_print = 0;
	va_list	args;

	if (format == NULL)
	       return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write (1, format, 1);
			char_print++;
		}
		format++;
	}
	va_end (args);
	return (char_print);
}

int	main(void)
{
	ft_printf("My name is Luka");
	return (0);
}
