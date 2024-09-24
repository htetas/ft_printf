#include "ft_printf.h"

int ft_numlen (int n, int precision)
{
    int len;
    unsigned int    nb;

    len = 1
    if (n < 0)
    {
        nb = (unsigned int)(n * -1);
        len++;
    }
    else
        nb = (unsigned int)n;
    while (nb >= 10)
    {
        nb = nb / 10;
        len++;
    }
    if (precision > len)
        return(precision);
    return (len);
}

void    ft_putnbr_prec(int n, int precision)
{
    if (n < 0)
    {
        ft_putchar_fd('-', 1);
        n = -n;
    }
    while (precision > (int)ft_findlen(n))
    {
        ft_putchar_fd('0', 1);
        precision--;
    }
    ft_putnbr_fd(n, 1);
}

int ft_printnbr(va_list args, t_flag flag)
{
    int count;
    int n;
    int sign;

    n = va_arg(args, int);
    sign = 0;
    if (n >= 0 && (flag.plus || flag.space))
        sign = 1;
    count = sign + ft_numlen(n, flag.precision);
    if (flag.minus == 0 && flag.zero == 0 && flag.width > len + sign)
        count += ft_padchar(flag.width - count, ' ');
    if (n > 0 && flag.plus)
        ft_putchar_fd('+', 1);
    else if (n > 0 && flag.space)
        ft_putchar_fd(' ', 1);
    else if (n < 0 && flag.zero == 0)
        ft_putchar_fd('-', 1);
    if (flag.zero && flag.dot == 0)
        count += ft_padchar(flag.width - count, '0');
    ft_putnbr_prec(n, flag.precision);
    if (flag.minus && flag.width > count)
        count += ft_padchar(flag.width - count, ' ');
    return (count);
}