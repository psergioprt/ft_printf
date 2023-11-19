/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:25:41 by pauldos-          #+#    #+#             */
/*   Updated: 2023/11/17 18:32:31 by psergiopr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

int	print_pointer_address(size_t x, char *base)
{
	char	string[25];
	int		i;
	int		len;
	int		temp;

	i = 0;
	len = 0;
	while (x != 0)
	{
		string[i++] = base[x % 16];
		x = x / 16;
	}
	while (i--)
	{
		temp = ft_putchar_fd(string[i], 1);
		if (temp < 0)
			return (-1);
		len += temp;
	}
	return (len);
}

int	ft_putptr(size_t x)
{
	int		len;
	int		result;

	if (write(1, "0x", 2) < 0)
		return (-1);
	len = 2;
	if (x == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		len++;
	}
	else
	{
		result = print_pointer_address(x, "0123456789abcdef");
		if (result < 0)
			return (-1);
		len += result;
	}
	return (len);
}
