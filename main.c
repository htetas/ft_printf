/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:07:15 by hsoe              #+#    #+#             */
/*   Updated: 2024/09/30 14:59:55 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	i;

	i = 0;
	i = printf("%%%\n");
	printf("The count is %d\n", i);
	i = ft_printf("%%%\n");
	printf("The count is %d\n", i);
	return (0);
}
