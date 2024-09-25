/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:15:26 by hsoe              #+#    #+#             */
/*   Updated: 2024/09/25 15:23:04 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_putnbr_prec(int n, int precision)
{
	unsigned int	nb;

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
		precision--;
	}
	ft_putunbr(nb);
}

int	ft_printnbr(va_list args, t_flag flag)
{
	int	count;
	int	n;
	int	sign;

	n = va_arg(args, int);
	sign = 0;
	if (n >= 0 && (flag.plus || flag.space))
		sign = 1;
	count = sign + ft_numlen(n, flag.precision);
	if (flag.minus == 0 && flag.zero == 0 && flag.width > count)
		count += ft_padchar(flag.width - count, ' ');
	if (n >= 0 && flag.plus)
		ft_putchar_fd('+', 1);
	else if (n >= 0 && flag.space)
		ft_putchar_fd(' ', 1);
	if (!flag.dot)
		ft_putnbr_prec(n, flag.width - sign);
	else
		ft_putnbr_prec(n, flag.precision);
	if (flag.minus && flag.width > count)
		count += ft_padchar(flag.width - count, ' ');
	return (count);
}
