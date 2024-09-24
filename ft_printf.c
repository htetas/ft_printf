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
	flag = ft_parse(s);
	if (s[i] != '\0')
	{
		if (flag->spec == 'c')
			len = ft_printchar(args, flag);
		if (flag->spec == 'X' || flag->spec == 'x')
			len = ft_printhex(args, flag);
		if (flag->spec == 's')
			len = ft_printstr(args, flag);
		if (flag->spec == 'p')
			len = ft_printptr(args, flag);
		if (flag->spec == 'i' || flag->spec == 'u')
			len = ft_printnbr(args, flag);
		if (flag->spec == '%')
		{
			ft_putchar_fd('%', 1);
			len = 1;
		}
	}
	return (len);
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
			len += ft_formats(args, *str + i + 1);
			while (ft_isspec(format[i]) == 0)
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