/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:58:42 by hsoe              #+#    #+#             */
/*   Updated: 2024/09/06 11:02:14 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(va_list args, t_flag flag)
{
	int	len;
	char	c;
	char	pad;

	len = 0;
	pad = ' ';
	if (flag.minus == 0 && flag.zero == 1)
		pad = '0';
	c = (char)va_arg(args, int);
	while (flag.minus == 0 && len < flag.width - 1)
	{
		write(1, &pad, 1);
		len++;
	}
	write(1, &c, 1);
	len++;
	while (flag.minus == 1 && len < flag.width)
	{
		write(1, " ", 1);
		len++;
	}
	return (len);
}