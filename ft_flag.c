/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:23:41 by hsoe              #+#    #+#             */
/*   Updated: 2024/09/06 11:30:12 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*ft_flaginit(void)
{
	t_flag	*flag;

	flag = (t_flag *)malloc(sizeof(t_flag));
	if (flag == NULL)
		return (NULL);
	flag->format = '\0';
	flag->sign = 0;
	flag->minwidth = 0;
	flag->maxwidth = 0;
	flag->length = 0;
	return (flag);
}

void	ft_getflag(const char *s, t_flag *flag)
{
	int	i;

	i = 0;
	while (s[i] != '\0' || ft_isflagspec(s[i]))
	{
		if (ft_isspec(s[i]))
			flag->format = s[i];
		if ()
	}
}