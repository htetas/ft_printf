/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflagspec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:17:49 by hsoe              #+#    #+#             */
/*   Updated: 2024/09/06 11:22:55 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isflag(const int c)
{
	if (c == '.' || c == '0' || c == '.' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int	ft_isspec(const int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' \
	|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_isflagspec(const int c)
{
	if (ft_isflag(c) || ft_isspec(c))
		return (1);
	return (0);
}