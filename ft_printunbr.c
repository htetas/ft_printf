#include "ft_printf.h"

int ft_unumlen (unsigned int n, int precision)
{
    int len;

    len = 1;
    while (n >= 10)
    {
        n = n / 10;
        len++;
    }
    if (precision > len)
        return(precision);
    return (len);
}

void    ft_putunbr(unsigned int n)
{
    if (n >= 10)
        ft_putunbr(n / 10);
    ft_putchar_fd((char)(n % 10 + '0'), 1);
}

void    ft_putunbr_prec(unsigned int n, int precision)
{
    while (precision > ft_unumlen(n, 0))
    {
        ft_putchar_fd('0', 1);
        precision--;
    }
    ft_putunbr(n);
}


int ft_printunbr(va_list args, t_flag flag)
{
    int count;
    unsigned int n;
    int sign;

    n = va_arg(args, unsigned int);
    sign = 0;
    if (n >= 0 && (flag.plus || flag.space))
        sign = 1;
    count = sign + ft_unumlen(n, flag.precision);
    if (flag.minus == 0 && flag.zero == 0 && flag.width > len + sign)
        count += ft_padchar(flag.width - count, ' ');
    if (flag.plus)
        ft_putchar_fd('+', 1);
    else if (flag.space)
        ft_putchar_fd(' ', 1);
    if (flag.zero && flag.dot == 0)
        count += ft_padchar(flag.width - count, '0');
    ft_putunbr_prec(n, flag.precision);
    if (flag.minus && flag.width > count)
        count += ft_padchar(flag.width - count, ' ');
    return (count);
}