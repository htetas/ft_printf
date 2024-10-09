/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:15:26 by hsoe              #+#    #+#             */
/*   Updated: 2024/10/03 13:20:13 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(int n, t_flag flag)
{
	int				len;
	unsigned int	nb;

	len = 1;
	if (n < 0)
	{
		nb = (unsigned int)(n * -1);
	}
	else
		nb = (unsigned int)n;
	while (nb >= 10)
	{
		nb = nb / 10;
		len++;
	}
	if (flag.precision > len && flag.dot)
		return (flag.precision);
	else if (flag.width > len && flag.zero)
		return (flag.width);
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
	while (precision > (int)ft_unumlen(nb, 0))
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

	sign = 0;
	if (n == 0 && flag.dot && flag.precision == 0)
		return (ft_padchar(flag.width, ' '));
	if ((n >= 0 && (flag.plus || flag.space)) || n < 0)
		sign = 1;
	count = sign;
	if (flag.dot)
		flag.zero = 0;
	if (!flag.minus && !flag.zero && \
	flag.width > sign + ft_numlen(n, flag))
		count += ft_padchar(flag.width - (ft_numlen(n, flag) + sign), ' ');
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
