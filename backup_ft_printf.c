/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:17:51 by pauldos-          #+#    #+#             */
/*   Updated: 2023/11/10 11:20:35 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_printf(const char *format, ...)
{
	int	chara_print;
	va_list	list_of_args;

	chara_print = 0;
	if (format == NULL)
		return (-1);
	va_start (list_of_args, format);
	while (*format) //A loop that iterates through the characters of the string
	{
		if (*format != '%') //if the format is not the % sign
		{
			write (1, format, 1); //Write the char to the standard output
			chara_print++;
		}
		else //If formar is the % sign
		{
			format++; //Skip '%' - Check the next character
			if (*format == '\0')
				break;
			if (*format == '%') //This solves %%
			{
				//Handle '%%' (double '%')
				write (1, format, 1);
				chara_print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(list_of_args, int); //Use va_arg(list, char) for char
				write (1, &c, 1);
				chara_print++;
			}
			else if (*format == 's')
			{
				char	*str = va_arg(list_of_args, char*);
				int	str_len = 0;
				//Calculate the length of the string
				while (str[str_len] != '\0')
					str_len++;
				//write the string to the standard output
				write(1, str, str_len);
				chara_print += str_len;
			}
		}
		format++;
	}
	va_end (list_of_args);
	return (chara_print);
}

int	main(void)
{
	int num = 123;

	ft_printf("My name is Luka");
	ft_printf("My name is %s\n", "Luka");
	ft_printf("My number is %d\n", num);
	return (0);
}
