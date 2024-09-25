/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:15:11 by hsoe              #+#    #+#             */
/*   Updated: 2024/09/25 15:45:02 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(va_list args, t_flag flag)
{
	unsigned long	ptr;
	int				count;
	char			*n;

	ptr = (unsigned long)va_arg(args, void *);
	count = 0;
	if (!ptr && flag.dot && flag.precision == 0)
		return (ft_padchar(flag.width, ' '));
	if (!ptr)
	{
		count += 6;
		n = "(nil)";
	}
	else
		count = 2 + ft_hexlen(ptr, 0);
	if (flag.minus == 0)
	{
		if (flag.zero && flag.dot == 0)
			count += ft_padchar(flag.width - count, '0');
		else
			count += ft_padchar(flag.width - count, ' ');
	}
	if (!ptr)
		ft_putstr_fd(n, 1);
	else
	{
		ft_putstr_fd("0x", 1);
		ft_puthex(ptr, HEXLOW);
	}
	if (flag.minus)
		count += ft_padchar(flag.width - count, ' ');
	return (count);
}
