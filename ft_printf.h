/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <hsoe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:39:44 by hsoe              #+#    #+#             */
/*   Updated: 2024/09/28 13:47:11 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_flag
{
	int		plus;
	int		space;
	int		sharp;
	int		minus;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	char	specifier;
}	t_flag;

# define HEXLOW	"0123456789abcdef"
# define HEXUP	"0123456789ABCDEF"

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, char *s);
t_flag	ft_flaginit(void);
void	ft_parseflag(char *str, t_flag *flag);
void	ft_parsewidth(char *str, t_flag *flag);
void	ft_parseprecision(char *str, t_flag *flag);
t_flag	ft_parse(char *str);
int		ft_printchar(int c, t_flag flag);
int		ft_printstr(char *s, t_flag flag);
int		ft_isspec(const int c);
int		ft_padchar(int len, char c);
void	ft_puthex(unsigned long n, char *base);
int		ft_hexlen(unsigned long n, int precision);
int		ft_printhex(unsigned int n, t_flag flag);
int		ft_unumlen(unsigned int n, int precision);
void	ft_putunbr(unsigned int n);
int		ft_printnbr(int n, t_flag flag);
int		ft_printunbr(unsigned int n, t_flag flag);
int		ft_printptr(unsigned long ptr, t_flag flag);

#endif
