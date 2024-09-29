/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:15:26 by hsoe              #+#    #+#             */
/*   Updated: 2024/09/28 13:59:12 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_abs(int n)
{
	if (n < 0)
		return ((unsigned int)-n);
	return ((unsigned int)n);
}

int	ft_numlen(int n, int precision)
{
	int				len;
	unsigned int	nb;

	len = 1;
	if (n < 0)
	{
		nb = (unsigned int)(n * -1);
		len++;
	}
	else
		nb = (unsigned int)n;
	while (nb >= 10)
	{
		nb = nb / 10;
		len++;
	}
	if (precision > len)
		return (precision);
	return (len);
}

int	ft_putnbr_prec(int n, int precision)
{
	unsigned int	nb;
	int				count;

	count = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		nb = (unsigned int)-n;
	}
	else
		nb = (unsigned int)n;
	while (precision > (int)ft_numlen(nb, 0))
	{
		ft_putchar_fd('0', 1);
		count++;
		precision--;
	}
	ft_putunbr(nb);
	count += ft_unumlen(nb, 0);
	return (count);
}

int	ft_printnbr(int n, t_flag flag)
{
	int	count;
	int	sign;

	count = 0;
	sign = 0;
	if ((n >= 0 && (flag.plus || flag.space)) || n < 0)
	{
		count++;
		sign = 1;
	}
	if (!flag.minus && !flag.zero && \
	flag.width > sign + ft_numlen(n, flag.precision))
		count += ft_padchar(flag.width - (sign + ft_unumlen(ft_abs(n), 0)), ' ');
	if (n >= 0 && flag.plus)
		ft_putchar_fd('+', 1);
	else if (n >= 0 && flag.space)
		ft_putchar_fd(' ', 1);
	if (!flag.dot && !flag.minus)
		count += ft_putnbr_prec(n, flag.width - count);
	else
		count += ft_putnbr_prec(n, flag.precision);
	if (flag.minus && flag.width > count)
		count += ft_padchar(flag.width - count, ' ');
	return (count);
}
