/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:45:21 by hsoe              #+#    #+#             */
/*   Updated: 2024/09/28 11:47:22 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	ft_flaginit(void)
{
	t_flag	flag;

	flag.plus = 0;
	flag.space = 0;
	flag.sharp = 0;
	flag.minus = 0;
	flag.zero = 0;
	flag.width = 0;
	flag.dot = 0;
	flag.precision = 0;
	flag.specifier = 0;
	return (flag);
}

void	ft_parseflag(char *str, t_flag *flag)
{
	int	i;

	i = 0;
	while (str[i] != '.' && !ft_isspec(str[i]))
	{
		if (str[i] == '+')
			flag->plus = 1;
		if (str[i] == ' ')
			flag->space = 1;
		if (str[i] == '#')
			flag->sharp = 1;
		if (str[i] == '-')
			flag->minus = 1;
		if (str[i] == '0' && ft_isdigit(str[i - 1]) == 0)
			flag->zero = 1;
		i++;
	}
}

void	ft_parsewidth(char *str, t_flag *flag)
{
	int	i;
	int	specified;

	i = 0;
	specified = 0;
	while (str[i] != '.' && !ft_isspec(str[i]))
	{
		if (str[i] > '0' && str[i] <= '9' && !specified)
		{
			flag->width = ft_atoi(str + i);
			specified = 1;
		}
		i++;
	}
}

void	ft_parseprecision(char *str, t_flag *flag)
{
	int	i;
	int	specified;

	i = 0;
	specified = 0;
	while (!ft_isspec(str[i]))
	{
		if (ft_isdigit(str[i]) && !specified)
		{
			flag->precision = ft_atoi(str + i);
			specified = 1;
		}
		i++;
	}
}

t_flag	ft_parse(char *str)
{
	int		i;
	t_flag	flag;

	i = 0;
	flag = ft_flaginit();
	ft_parseflag(str, &flag);
	ft_parsewidth(str, &flag);
	while (str[i] != '.' && !ft_isspec(str[i]) && str[i] != '\0')
		i++;
	if (str[i] == '.')
	{
		flag.dot = 1;
		ft_parseprecision(str + i + 1, &flag);
	}
	while (!ft_isspec(str[i]) && str[i] != '\0')
		i++;
	if (ft_isspec(str[i]))
		flag.specifier = str[i];
	return (flag);
}
