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

	flag->format = '\0';
	flag->sign = 0;
	flag->minwidth = 0;
	flag->maxwidth = 0;
	flag->length = 0;
	return (flag);
}

char	*ft_getflag(const char *format, size_t start)
{
	size_t	i;
	char	*flag;

	while(format[start] != '\0' || ft_isspec(format[start]) != )
}