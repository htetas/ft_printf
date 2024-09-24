/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:00:38 by hsoe              #+#    #+#             */
/*   Updated: 2024/09/06 11:02:12 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(va_list args, t_flag flag)
{
	int	count;
	char	pad;
	char	*s;

	s = (char *)va_arg(args, char *);
	count = ft_strlen(s);
	pad = ' ';
	if (flag.minus == 0 && flag.zero == 1)
		pad = '0';
	while (flag.minus == 0 && count < flag.width - 1)
	{
		write(1, &pad, 1);
		count++;
	}
	ft_putstr_fd(s, 1);
	while (flag.minus == 1 && count < flag.width)
	{
		write(1, " ", 1);
		count++;
	}
	return (count);
}