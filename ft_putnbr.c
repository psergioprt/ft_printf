/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:55:06 by pauldos-          #+#    #+#             */
/*   Updated: 2023/11/16 11:02:01 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
