/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:15:40 by hsoe              #+#    #+#             */
/*   Updated: 2024/09/30 16:10:33 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putsharp(t_flag flag)
{
	if (flag.specifier == 'X')
		ft_putstr_fd("0X", 1);
	else
		ft_putstr_fd("0x", 1);
}

void	ft_puthex_prec(unsigned int n, int precision, char *base)
{
	while (precision > ft_hexlen((unsigned long)n, 0))
	{
		ft_putchar_fd('0', 1);
		precision--;
	}
	ft_puthex((unsigned long)n, base);
}

int	ft_printhex(unsigned int n, t_flag flag)
{
	int				count;
	char			*base;

	if (flag.specifier == 'X')
		base = "0123456789ABCDEF";
	else if (flag.specifier == 'x')
		base = "0123456789abcdef";
	count = 0;
	if (n == 0)
		flag.sharp = 0;
	if (flag.sharp)
		count += 2;
	if (flag.dot)
		flag.zero = 0;
	if (n == 0 && flag.dot && !flag.precision)
		return (ft_padchar(flag.width, ' '));
	count += ft_hexlen((unsigned long)n, flag.precision);
	if (!flag.minus && !flag.zero && flag.width > count)
		count += ft_padchar(flag.width - count, ' ');
	if (flag.sharp == 1 && n != 0)
		ft_putsharp(flag);
	if (flag.zero && !flag.dot && !flag.minus)
		count += ft_padchar(flag.width - count, '0');
	ft_puthex_prec(n, flag.precision, base);
	if (flag.minus && flag.width > count)
		count += ft_padchar(flag.width - count, ' ');
	return (count);
}
