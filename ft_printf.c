/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:08:59 by pauldos-          #+#    #+#             */
/*   Updated: 2023/11/09 12:34:54 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_printf(const char *format, ...)
{
	int	chara_print
	va_list	list_of_args;

	chara_print = 0;

	if (format == NULL)
		return (-1);
	va_start(list_of_args, format);
	while (*format)
	{
		if(*format != %)
		{
			write(1, format, 1);
			chara_print++;
		}
		else
		{
			format++;
		}
		if (*format == '\0')
		{
			break;
		}
		if (*format == '%')
		{
			write(1, format, 1);
			chara_print++;
		}
		else if (format == 'c')
		{
			char	c = va_arg(list_of_args, int);
			write(1, &c, 1);
			chara_print++;
		}
		write (1, num, strlen(num));
		if (format == '%')
		{

		}

	}
	va_end(list_of_args);

}
