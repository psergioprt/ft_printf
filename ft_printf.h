/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:10:39 by pauldos-          #+#    #+#             */
/*   Updated: 2023/11/16 11:27:16 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

int		ft_strlen(char *str);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb, int i);
int		ft_putnbr_u(unsigned int nb, int i);
void	ft_putnbr_hex_digit(int hex_digit, int uppercase);
int		ft_putnbr_hex(unsigned long long nb, int i, int uppercase);
char	*ft_strchr(const char *str, int c);
int		ft_putptr(void *ptr, int i);

#endif
