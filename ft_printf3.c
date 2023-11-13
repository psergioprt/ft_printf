/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:19:30 by pauldos-          #+#    #+#             */
/*   Updated: 2023/11/13 10:46:11 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	write_c(char	c)
{
	int	char_print;

	write (1, &char, 1);


}

int	ft_printf(const char *format, ...)
{
	int		char_print;
	va_list	list_of_args;
	char	c;
	char	*str;

	char_print = 0;
	if (format == NULL)
		return (-1);
	va_start(list_of_args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write (1, format, 1);
			char_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break ;
			if (*format == '%')
			{
				write (1, format, 1);
				char_print++;
			}
			if (*format == 'c')
			{
				c = va_arg(list_of_args, int);
				write (1, &c, 1);
				char_print++;
			}
			if (*format == 's')
			{
				str = va_arg(list_of_args, char *);
				write (1, str, str_len(str));
				char_print += str_len(str);
			}
		}
		format++;
	}
	va_end(list_of_args);
	return (char_print);
}

int	main(void)
{
	char	*str;
	char	c;

	str = "is Luka";
	c = 'Z';
	ft_printf("My name %s. Character: %c\n", str, c);
	return (0);
}
