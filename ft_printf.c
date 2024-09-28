/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:39:10 by hsoe              #+#    #+#             */
/*   Updated: 2024/09/28 13:46:56 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnum(va_list args, t_flag flag)
{
	if (flag.specifier == 'i' || flag.specifier == 'd')
		return (ft_printnbr((int)va_arg(args, int), flag));
	else
		return (ft_printunbr((unsigned int)va_arg(args, unsigned int), flag));
}

int	ft_formats(va_list args, char *s)
{
	int		len;
	t_flag	flag;

	len = 0;
	flag = ft_parse(s);
	if (s)
	{
		if (flag.specifier == 'c')
			len = ft_printchar((char)va_arg(args, int), flag);
		if (flag.specifier == 'X' || flag.specifier == 'x')
			len = ft_printhex((unsigned int)va_arg(args, unsigned int), flag);
		if (flag.specifier == 's')
			len = ft_printstr((char *)va_arg(args, char *), flag);
		if (flag.specifier == 'p')
			len = ft_printptr((unsigned long)va_arg(args, void *), flag);
		if (flag.specifier == 'i' || flag.specifier == 'u' || \
		flag.specifier == 'd')
			len = ft_printnum(args, flag);
		if (flag.specifier == '%')
		{
			ft_putchar_fd('%', 1);
			len = 1;
		}
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_formats(args, (char *)format + i);
			while (format[i] && !ft_isspec(format[i]))
				i++;
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
