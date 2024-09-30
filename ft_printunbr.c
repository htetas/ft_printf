/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:11:03 by hsoe              #+#    #+#             */
/*   Updated: 2024/09/30 13:57:32 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unumlen(unsigned int n, int precision)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	if (precision > len)
		return (precision);
	return (len);
}

void	ft_putunbr_prec(unsigned int n, int precision)
{
	while (precision > ft_unumlen(n, 0))
	{
		ft_putchar_fd('0', 1);
		precision--;
	}
	ft_putunbr(n);
}

int	ft_printunbr(unsigned int n, t_flag flag)
{
	int				count;
	int				sign;

	sign = 0;
	if (n == 0 && flag.dot && flag.precision == 0)
		return (ft_padchar(flag.width, ' '));
	if (flag.plus || flag.space)
		sign = 1;
	count = sign + ft_unumlen(n, flag.precision);
	if (flag.dot)
		flag.zero = 0;
	if (!flag.minus && !flag.zero && flag.width > count)
		count += ft_padchar(flag.width - count, ' ');
	if (flag.plus)
		ft_putchar_fd('+', 1);
	else if (flag.space)
		ft_putchar_fd(' ', 1);
	if (flag.zero && flag.dot == 0)
		count += ft_padchar(flag.width - count, '0');
	ft_putunbr_prec(n, flag.precision);
	if (flag.minus && flag.width > count)
		count += ft_padchar(flag.width - count, ' ');
	return (count);
}
