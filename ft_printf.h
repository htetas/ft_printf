/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:39:44 by hsoe              #+#    #+#             */
/*   Updated: 2024/09/06 11:28:53 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct s_flag
{
	int	plus;
	int	space;
	int	sharp;
	int	minus;
	int	zero;
	int	width;
	int	dot;
	int	precision;
	char	specifier;
}	t_flag;

#endif