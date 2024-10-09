/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:15:11 by hsoe              #+#    #+#             */
/*   Updated: 2024/10/03 10:25:40 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long ptr, t_flag flag)
{
	int				count;
	int				l;

	count = 0;
	if (!ptr && flag.dot && flag.precision == 0)
		return (ft_padchar(flag.width, ' '));
	if (!ptr)
	{
		flag.dot = 0;
		return (ft_printstr("(nil)", flag));
	}
	l = ft_hexlen(ptr, flag.precision) + 2;
	if (!flag.minus && flag.width > l && (!flag.zero || flag.dot))
		count += ft_padchar(flag.width - l, ' ');
	ft_putstr_fd("0x", 1);
	if (flag.zero && !flag.dot && !flag.minus && flag.width > l)
		count += ft_padchar (flag.width - l, '0');
	if (flag.dot && flag.precision > ft_hexlen(ptr, 0))
		count += ft_padchar (flag.precision - ft_hexlen(ptr, 0), '0');
	ft_puthex(ptr, "0123456789abcdef");
	count += ft_hexlen(ptr, 0);
	if (flag.minus)
		count += ft_padchar(flag.width - 2 - count, ' ');
	return (count + 2);
}
