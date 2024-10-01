/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:58:42 by hsoe              #+#    #+#             */
/*   Updated: 2024/10/01 11:15:55 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c, t_flag flag)
{
	int		count;

	count = 0;
	if (!c)
		c = 0;
	if (flag.minus == 0 && flag.width > 1)
		count += ft_padchar(flag.width - 1, ' ');
	write(1, &c, 1);
	count++;
	if (flag.minus == 1 && count < flag.width)
		count += ft_padchar(flag.width - count, ' ');
	return (count);
}
