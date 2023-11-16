/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:04:34 by pauldos-          #+#    #+#             */
/*   Updated: 2023/11/16 11:03:54 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nb, int i)
{
	int long	num;

	num = nb;
	if (nb < 10)
		i = ft_putchar(nb + '0');
	else
	{
		i = ft_putnbr_u(nb / 10, i);
		i = ft_putnbr_u(nb % 10, i);
	}
	return (i);
}
