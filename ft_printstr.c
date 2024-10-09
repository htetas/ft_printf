/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:00:38 by hsoe              #+#    #+#             */
/*   Updated: 2024/10/03 09:14:51 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pristrlen(char *s, t_flag flag)
{
	int	len;

	len = ft_strlen(s);
	if (flag.dot && flag.precision < len)
		len = flag.precision;
	return (len);
}

void	ft_printstr_prec(char *s, int len)
{
	int	i;

	i = 0;
	while (len)
	{
		write (1, &s[i], 1);
		len--;
		i++;
	}
}

int	ft_printstr(char *s, t_flag flag)
{
	int		count;

	if (!s && flag.dot && flag.precision < (int)ft_strlen("(null)"))
		return (ft_padchar(flag.width, ' '));
	if (!s)
		s = (char *)"(null)";
	count = ft_pristrlen(s, flag);
	while (flag.minus == 0 && count < flag.width)
	{
		write(1, " ", 1);
		count++;
	}
	ft_printstr_prec(s, ft_pristrlen(s, flag));
	while (flag.minus == 1 && count < flag.width)
	{
		write(1, " ", 1);
		count++;
	}
	return (count);
}
