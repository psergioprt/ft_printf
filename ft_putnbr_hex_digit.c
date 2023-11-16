/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_digit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:09:58 by pauldos-          #+#    #+#             */
/*   Updated: 2023/11/16 11:03:07 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
