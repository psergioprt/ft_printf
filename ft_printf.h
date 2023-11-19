/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergioprt <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:46:57 by psergiopr         #+#    #+#             */
/*   Updated: 2023/11/17 18:47:00 by psergiopr        ###   ########.fr       */
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
int		ft_print_int(int n);
int		ft_print_int_u(unsigned int n);
void	ft_putnbr_hex_digit(int hex_digit, int uppercase);
int		ft_putnbr_hex(unsigned long long nb, int i, int uppercase);
char	*ft_strchr(const char *str, int c);
int		ft_putptr(void *ptr, int i);

#endif
