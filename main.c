/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:07:15 by hsoe              #+#    #+#             */
/*   Updated: 2024/09/28 13:48:37 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	i;

	i = printf("%.03s", "");
	printf("The count is %d\n", i);
	i = ft_printf("%.03s", "");
	printf("The count is %d\n", i);
	return (0);
}
