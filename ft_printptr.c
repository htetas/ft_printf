/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:15:11 by hsoe              #+#    #+#             */
/*   Updated: 2024/09/28 10:37:14 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long ptr, t_flag flag)
{
	int				count;

	count = 0;
	if (!ptr && flag.dot && flag.precision == 0)
		return (ft_padchar(flag.width, ' '));
	if (!ptr)
	{
		return (ft_printstr("(nil)", flag));
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
	ft_putstr_fd("0x", 1);
	ft_puthex(ptr, HEXLOW);
	if (flag.minus)
		count += ft_padchar(flag.width - count, ' ');
	return (count);
}
