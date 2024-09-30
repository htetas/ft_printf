/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:15:57 by hsoe              #+#    #+#             */
/*   Updated: 2024/09/30 13:39:31 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isspec(const int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' \
	|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_padchar(int len, char c)
{
	int	count;

	count = 0;
	while (len > 0)
	{
		ft_putchar_fd(c, 1);
		count++;
		len--;
	}
	return (count);
}

void	ft_puthex(unsigned long n, char *base)
{
	if (n >= 16)
		ft_puthex(n / 16, base);
	ft_putchar_fd(base[n % 16], 1);
}

int	ft_hexlen(unsigned long n, int precision)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n = n / 16;
		len++;
	}
	if (precision > len)
		return (precision);
	return (len);
}

void	ft_putunbr(unsigned int n)
{
	if (n >= 10)
		ft_putunbr(n / 10);
	ft_putchar_fd((char)(n % 10 + '0'), 1);
}
