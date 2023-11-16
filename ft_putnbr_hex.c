/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:16:53 by pauldos-          #+#    #+#             */
/*   Updated: 2023/11/16 11:02:34 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
