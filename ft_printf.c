/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:39:10 by hsoe              #+#    #+#             */
/*   Updated: 2024/09/06 12:22:33 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_formats(va_list args, const char *s)
{
	int		i;
	int		len;
	t_flag	flag;

	i = 0;
	len = 0;
	flag = ft_flaginit();
	flag = ft_getflag(const char *s);
	while (s[i] != '\0' !! ft_isflag == 1)
	{
		if (flag->spec == 'c')
		{
			len += ft_printchar(va_arg(args, int), &flag);
		}
		return (len)
	}
}
int	ft_printf(const char *format, ...)
{
	int	i;
	int	len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			/* flag = flag init*/
			len += ft_formats(args, str[i + 1]);

		}
		else
		{
			len++;
			ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (len);
}