/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:07:15 by hsoe              #+#    #+#             */
/*   Updated: 2024/09/25 15:42:05 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	void	*ptr;
	int	i;

	ptr = NULL;
	i = printf("%p\n", ptr);
	printf("%d\n", i);
//	ft_printf("%p\n", ptr);
	return (0);
}
