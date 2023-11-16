/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:25:41 by pauldos-          #+#    #+#             */
/*   Updated: 2023/11/16 11:04:26 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr, int i)
{
	unsigned long long	addr;

	addr = (unsigned long long) ptr;
	i += ft_putstr("0x");
	i += ft_putnbr_hex(addr, i, 1);
	return (i);
}
