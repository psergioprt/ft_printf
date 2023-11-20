/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergioprt <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:47:29 by psergiopr         #+#    #+#             */
/*   Updated: 2023/11/20 11:50:00 by psergiopr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hex(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char	*hex_to_str(unsigned long n, char *base)
{
	int		size;
	char	*hex;

	size = count_hex(n);
	hex = (char *)malloc(sizeof(char) * (size + 1));
	if (!hex)
		return (NULL);
	hex[size] = '\0';
	while (size > 0)
	{
		hex[size - 1] = base[n % 16];
		n = n / 16;
		size--;
	}
	return (hex);
}

int	ft_print_ptr(void *nbr, char *base)
{
	char			*str;
	int				len;

	if (!nbr)
	{
		ft_putstr("(nil)");
		return (5);
	}
	str = hex_to_str((unsigned long long)nbr, base);
	if ((unsigned long)nbr == 0)
	{
		ft_putchar('0');
	}
	else
	{
		ft_putstr("0x");
		len = ft_putstr(str) + 2;
	}
	free(str);
	return (len);
}
